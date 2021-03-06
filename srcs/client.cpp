/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:20:14 by user42            #+#    #+#             */
/*   Updated: 2022/06/22 12:12:32 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <sstream>
#include "server.hpp"
#include "utils.hpp"
#include "replies.hpp"
#include "command.hpp"

client::client() {
	clear_client();
}

client::~client() {
}

bool    client::check_buff() {
	if (this->buffer[this->buffer.length() - 2] == '\r' && this->buffer[this->buffer.length() - 1] == '\n')
		return true;
	return false;
}

void    client::clear_buff() {
	this->buffer = "";
}

void    client::clear_client() {
	this->client_socket = 0;
	this->nickname = "";
	this->username = "";
	this->realname = "";
	this->pass = "";
	this->host = "";
	this->server_name = "";
	this->registration_status = "Unregistered";
	this->is_registered = false;
}

std::string client::get_prefix() {
	return this->nickname + "!" + this->username + "@" + this->server_name;
}

void    client::finish_registration(server & serv) {
	std::string toSend;
	std::string nul = "";
	std::string nbr = static_cast<std::ostringstream *>( &(std::ostringstream() << serv.connectedUsers) )->str();
	std::string nbChannels = static_cast<std::ostringstream *>( &(std::ostringstream() << serv.nbChannels) )->str();
	this->serv = &serv;

	toSend = ": NICK :" + this->nickname + LINEEND;
	toSend += ":" + get_prefix() + " 001 " + this->nickname + " " + get_replies(1, get_prefix(), nul, nul, nul, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 002 " + this->nickname + " " + get_replies(2, serv._config.version, nul, nul, nul, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 003 " + this->nickname + " " + get_replies(3, serv.date, nul, nul, nul, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 004 " + this->nickname + " " + get_replies(4, serv._config.server_name, serv._config.version, serv._config.umod, serv._config.cmod, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 251 " + this->nickname + " " + get_replies(251, nbr, "0", "1", nul, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 252 " + this->nickname + " " + get_replies(252, "0", nul, nul, nul, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 253 " + this->nickname + " " + get_replies(253, "0", nul, nul, nul, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 254 " + this->nickname + " " + get_replies(254, nbChannels, nul, nul, nul, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 255 " + this->nickname + " " + get_replies(255, nbr, "1", nul, nul, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 375 " + this->nickname + " " + get_replies(375, serv._config.server_name, nul, nul, nul, nul, nul, nul) + LINEEND;
	toSend += ":" + get_prefix() + " 372 " + this->nickname + " " + get_replies(372, serv._config.motd, nul, nul, nul, nul, nul, nul) + LINEEND;
	std::cout << toSend << std::endl;
	send(this->client_socket, toSend.c_str(), toSend.length(), 0);
}

bool    client::registr(std::string buffer, server & serv) {
	int index = 0;
	int tmpdex = 0;
	std::string tmp = buffer.substr(0, 5);
	if (this->registration_status.compare("Unregistered") == 0) {
		if (tmp.compare("CAP L") == 0) {
			index = 5;
			while (buffer[index] && buffer[index] != '\n') {
				index++;
			}
			if (buffer[index + 1]) {
				index++;
				buffer.erase(0, index);
				return registr(buffer, serv);
			}
		}
		if (tmp.compare("PASS ") == 0) {
			index = 5;
			while (buffer[index] && buffer[index] != '\n') {
				index++;
			}
			this->pass = buffer.substr(5, index - 4);
			clean_string(this->pass);
			if (this->pass != serv.getPassword()) {
				printerr(ERR_PASSWDMISMATCH());
				serv.sendToUser(this->client_socket, ERR_PASSWDMISMATCH());
				return false;
			}
			this->registration_status = "PASS";
			if (buffer[index + 1]) {
				index++;
				buffer.erase(0, index);
				return registr(buffer, serv);
			}
		}
		else {
			printerr(ERR_PASSWDMISMATCH());
			serv.sendToUser(this->client_socket, ERR_PASSWDMISMATCH());
			return false;
		}
	}
	if (this->registration_status.compare("PASS") == 0 || this->registration_status.compare("Unregistered") == 0) {
		if (tmp.compare("NICK ") == 0) {
			index = 5;
			while (buffer[index] && buffer[index] != '\n')
				index++;
			std::string nickname = buffer.substr(5, index - 4);
			clean_string(nickname);

			if (nickname.empty()) {
				printerr(ERR_NONICKNAMEGIVEN()); // EMPTY NICKNAME
				serv.sendToUser(this->client_socket, ERR_NONICKNAMEGIVEN());
				return false;
			}
			else if (!isValidNickname(nickname)) {
				printerr(ERR_ERRONEUSNICKNAME(nickname)); // UNVALID NICKNAME
				serv.sendToUser(this->client_socket, ERR_ERRONEUSNICKNAME(nickname));
				return false;
			}
			else {
				std::string newName = nickname;
				int i = 0;
				while (!isNicknameAvailable(newName, serv.clients)) {
					newName = nickname + "_" + static_cast<std::ostringstream *>( &(std::ostringstream() << ++i) )->str();
				}
				std::cerr << "Final name is: " << newName << std::endl;
				this->nickname = newName;
				this->registration_status = "NICK";
				if (buffer[index + 1]) {
					index++;
					buffer.erase(0, index);
					return registr(buffer, serv);
				}	
			}
		}
	}
	if (this->registration_status.compare("NICK") == 0) {
		if (tmp.compare("USER ") == 0) {
			index = 5;
			tmpdex = index;
			while (buffer[index] && buffer[index] != ' ') {
				index++;
			}
			this->username = buffer.substr(tmpdex, index - (tmpdex));
			index++;
			tmpdex = index;
			while (buffer[index] && buffer[index] != ' ') {
				index++;
			}
			this->host = buffer.substr(tmpdex, index - (tmpdex));
			index++;
			tmpdex = index;
			while (buffer[index] && buffer[index] != ' ') {
				index++;
			}
			this->server_name = buffer.substr(tmpdex, index - (tmpdex));
			index++;
			index++;
			tmpdex = index;
			while (buffer[index] && buffer[index] != '\n') {
				index++;
			}
			this->realname = buffer.substr(tmpdex, index - (tmpdex - 1));
			// std::cout << "USER :" << this->username << "-" << this->host << "-" << this->server_name << "-" << this->realname << std::endl;
			clean_string(this->username);
			this->registration_status = "USER";
			this->is_registered = true;
			finish_registration(serv);
		}
	}
	return true;
}
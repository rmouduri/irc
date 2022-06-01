/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:09:54 by user42            #+#    #+#             */
/*   Updated: 2022/05/31 21:29:06 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.hpp"
#include "replies.hpp"

bool isNicknameAvailable(std::string nickname, std::vector<client> clients) {
	for (std::vector<client>::const_iterator cit = clients.begin(), cite = clients.end(); cit != cite; ++cit)
		if (nickname == cit->nickname)
			return false;
	return true;
}

bool isValidNickname(std::string nickname) {
	for (int i = 0; nickname[i]; ++i)
		if (nickname[i] < 32)
			return false;
	return true;
}

std::string    nick(std::string nickname, server & serv, client & cli){
	std::string toRet = ":" + cli.get_prefix() + " NICK :" + nickname;

	(void)serv;
	clean_string(nickname);

	if (nickname.empty())
		return ERR_NONICKNAMEGIVEN(); // EMPTY NICKNAME
	else if (!isValidNickname(nickname))
		return ERR_ERRONEUSNICKNAME(nickname); // UNVALID NICKNAME
	else if (!isNicknameAvailable(nickname, serv.clients))
		return ERR_NICKNAMEINUSE(nickname); // UNAVAILABLE NICKNAME

	cli.nickname = nickname;
	return toRet;
}
std::string    ping(std::string args, __attribute__((unused)) server &serv, __attribute__((unused)) client& cli){
	return "PONG " + args;
}
std::string    pong(std::string args, __attribute__((unused)) server &serv, __attribute__((unused)) client& cli){
	return "PING " + args;
}
std::string    join(std::string args, __attribute__((unused)) server &serv, __attribute__((unused)) client& cli){
	int index = 0;
	std::string toRet;
	std::cout << toRet[0] << std::endl;
	while (index < 30 && serv.channels[index].name != ""){
		if (serv.channels[index].name.compare(args) == 0){
			serv.channels[index].add_client(cli.client_socket, cli);
			if (serv.channels[index].topic != ""){
				toRet += ":" + cli.get_prefix() + " 332 " + cli.nickname + " " + get_replies(332, serv.channels[index].name, serv.channels[index].topic, "", "", "","","") + LINEEND;
			}
			toRet += ":" + cli.get_prefix() + " 353 " + cli.nickname + " " + get_replies(353, serv.channels[index].mods, serv.channels[index].name, serv.channels[index].get_nicks("@"), "", "", "", "") + LINEEND;
			toRet += ":" + cli.get_prefix() + " 366 " + cli.nickname + " " + get_replies(366, serv.channels[index].name, "", "", "", "", "", "") + LINEEND;
			toRet += ":" + cli.get_prefix() + " JOIN :" + serv.channels[index].name;
			return toRet;
		}
		index++;
	}
	if (index >= 30){
		std::cout << "all chann full" << std::endl;
	}
	else{
		serv.channels[index].add_op(cli.client_socket, cli);
		serv.channels[index].name = args;
		if (serv.channels[index].topic != ""){
			toRet += ":" + cli.get_prefix() + " 332 " + cli.nickname + " " + get_replies(332, serv.channels[index].name, serv.channels[index].topic, "", "", "","","") + LINEEND;
		}
		toRet += ":" + cli.get_prefix() + " 353 " + cli.nickname + " " + get_replies(353, serv.channels[index].mods, serv.channels[index].name, serv.channels[index].get_nicks("@"), "", "", "", "") + LINEEND;
		toRet += ":" + cli.get_prefix() + " 366 " + cli.nickname + " " + get_replies(366, serv.channels[index].name, "", "", "", "", "", "") + LINEEND;
		toRet += ":" + cli.get_prefix() + " JOIN :" + serv.channels[index].name;
	}
	return toRet;
}
std::string    part(std::string args, __attribute__((unused)) server &serv, __attribute__((unused)) client& cli){
	std::string toRet = ":" + cli.get_prefix() + " PART " + args;
	return toRet;
}
std::string    quit(std::string args, __attribute__((unused)) server &serv, __attribute__((unused)) client& cli){
	close(cli.client_socket);
	cli.clear_client();
	return args;
}
std::string    privmsg(std::string args, __attribute__((unused)) server &serv, __attribute__((unused)) client& cli){
	std::string toRet = ":" + cli.get_prefix() + " PRIVMSG " + args + "\r\n";
	std::string target;
	int index = 0;

	while (args[index] && args[index] != ' '){
		index++;
	}
	target = args.substr(0, index);
	
	index = 0;

	if (target[0] == '#'){
		while (index < 30){
			if (serv.channels[index].name.compare(target) == 0){
				serv.channels[index].send_to_clients(toRet, cli.client_socket);
			}
			index++;
		}
	}
	else
	{
		while (index < 30){
			if (serv.clients[index].nickname.compare(target) == 0){
				send(serv.clients[index].client_socket, toRet.c_str(), toRet.length(), 0);
				send(serv.clients[index].client_socket, "SALUT SA VA\r\n", 13, 0);
				break;
			}
			index++;
		}
	}
	
	
	return "";
}

std::string    mode(std::string args, __attribute__((unused)) server &serv, __attribute__((unused)) client& cli){
	int index = 0;

	while (index < 30){
		if (serv.channels[index].name.compare(args) == 0){
			break;
		}
		index++;
	}
	if (index >= 30){
		return "";
	}
	std::string toRet = ":" + cli.get_prefix() + " 324 " + cli.nickname + " " + get_replies(324, serv.channels[index].name, serv.channels[index].mods, "", "", "","","");
	return toRet;
}

std::string    who(std::string args, __attribute__((unused)) server &serv, __attribute__((unused)) client& cli){
	int index = 0;

	while (index < 30){
		if (serv.channels[index].name.compare(args) == 0){
			break;
		}
		index++;
	}
	if (index >= 30){
		return "";
	}
	std::string toRet = ":" + cli.get_prefix() + " 315 " + cli.nickname + " " + get_replies(315, serv.channels[index].get_users(), "", "", "", "", "", "");
	return toRet;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:41:46 by user42            #+#    #+#             */
/*   Updated: 2022/06/22 12:07:15 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include <vector>

#include "config.hpp"
#include <fcntl.h>
#include "channel.hpp"


class server;

#include "client.hpp"
#include "command.hpp"


class server
{
	private:
		int port;
		int addrlen;
		int master_socket;
		struct sockaddr_in address;
		std::string		user_cmd[9];
		std::string		(*f[9])(std::string, server&, client&);

		std::string		password;
		std::string getCurrentDate();

	public:
		void	init_server(std::string _port, std::string _password);
		void	process(std::string buffer, client&);
		void	run_server();
		void	sendToUser(int sd, std::string str);

		const std::string	getPassword(void) const;

		config	_config;
		std::vector<client> clients;
		channel<client> channels[30];
		int nbChannels;
		std::string		date;
		int				connectedUsers;
		server();
		~server();
};

#endif
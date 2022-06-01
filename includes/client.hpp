/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:09:22 by user42            #+#    #+#             */
/*   Updated: 2022/05/31 01:34:12 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include "utils.hpp"

class client;

#include "server.hpp"

 
#define LINEEND "\r\n"

class client
{
private:
public:
	int client_socket;

	std::string nickname;
	std::string username;
	std::string realname;
	std::string pass;
	std::string host;
	std::string server_name;
	std::string registration_status;
	std::string buffer;

	bool		is_registered;

	server *serv;


	bool	registr(std::string buffer, server &serv);
	bool	check_buff();
	void	finish_registration(server &serv);
	void	process(std::string);
	std::string get_prefix();
	void	clear_client();
	void	clear_buff();

	client();
	~client();
};

#endif
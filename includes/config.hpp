/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouduri <rmouduri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:19:11 by user42            #+#    #+#             */
/*   Updated: 2022/06/22 11:59:33 by rmouduri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <iostream>
#include <fcntl.h>
#include "unistd.h"

class config
{
private:
public:
	std::string server_name;
	std::string version;
	std::string motd;
	std::string umod;
	std::string cmod;

	void	edit_config(std::string);
	void	init_config(std::string);

	config();
	~config();
};

#endif
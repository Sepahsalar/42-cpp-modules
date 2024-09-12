/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:34:50 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/12 14:14:59 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::_debug()
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon ";
	std::cout << "for my 7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!" << std::endl;
}

void	Harl::_info()
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon ";
	std::cout << "costs more money. You didn't put enough bacon in my burger!" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have ";
	std::cout << "some extra bacon for free. I've been coming for years ";
	std::cout << "whereas you started working here since last month." << std::endl;
}

void	Harl::_error()
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! ";
	std::cout << "I want to speak to the manager now." << std::endl;
}

void	Harl::filter(std::string level)
{
	const std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int					log_level = -1;

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			log_level = i;
			break;
		}
	}
	switch (log_level)
	{
		case 0:
			_debug();
		case 1:
			_info();
		case 2:
			_warning();
		case 3:
			_error();
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

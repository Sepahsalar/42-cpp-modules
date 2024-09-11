/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:34:50 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
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
	int log_level = 0;
	
	if (level == "DEBUG")
		log_level = 1;
	else if (level == "INFO")
		log_level = 2;
	else if (level == "WARNING")
		log_level = 3;
	else if (level == "ERROR")
		log_level = 4;
	else
		log_level = 0;

	switch (log_level)
	{
		case 1:
			_debug();
		case 2:
			_info();
		case 3:
			_warning();
		case 4:
			_error();
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}


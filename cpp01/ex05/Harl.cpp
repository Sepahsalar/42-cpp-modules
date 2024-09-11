/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:34:50 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 16:25:08 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << "DEBUG: I love having extra bacon for my";
	std::cout << " 7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I really do!" << std::endl;
}

void	Harl::info()
{
	std::cout << "INFO: I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn't put enough bacon in my burger!" << std::endl;
}

void	Harl::warning()
{
	std::cout << "WARNING: I think I deserve to have some extra bacon for free.";
	std::cout << "I've been coming for years whereas you started working here";
	std::cout << " since last month." << std::endl;
}

void	Harl::error()
{
	std::cout << "ERROR: This is unacceptable!";
	std::cout << " I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	if (level.empty())
	{
        std::cout << "Invalid level: EMPTY" << std::endl;
        return;
    }
	void	(Harl::*functions[])() =
	{
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning, 
		&Harl::error
	};
	std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "Invalid level: " << level << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:34:50 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 16:07:20 by asohrabi         ###   ########.fr       */
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

void	Harl::_handleLevel(std::string level)
{
	if (level == "DEBUG")
	{
		this->_debug();
		this->_info();
		this->_warning();
		this->_error();
	} 
	else if (level == "INFO")
	{
		this->_info();
		this->_warning();
		this->_error();
	} 
	else if (level == "WARNING")
	{
		this->_warning();
		this->_error();
	} 
	else if (level == "ERROR")
		this->_error(); 
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::filter(std::string level)
{
	_handleLevel(level);
}


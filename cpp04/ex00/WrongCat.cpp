/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:35:17 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copied" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WrongCat assigned" << std::endl;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroyed" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:04 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal &other)
{
	*this = other;
	std::cout << "Animal copied" << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "Animal assigned" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Some generic animal sound" << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:04 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 18:42:32 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	*this = other;
	std::cout << "AAnimal copied" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "AAnimal assigned" << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destroyed" << std::endl;
}

std::string	AAnimal::getType() const
{
	return this->type;
}

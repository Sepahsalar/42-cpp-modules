/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:28:15 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/23 11:23:11 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure	&Cure::operator=(Cure const &other)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria	*Cure::clone() const
{
	try
	{
		return new Cure(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << std::endl;
		return nullptr;
	}
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

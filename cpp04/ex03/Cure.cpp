/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:28:15 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/19 14:50:28 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const &other) : AMateria(other) {}

Cure	&Cure::operator=(Cure const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {}

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
	// return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

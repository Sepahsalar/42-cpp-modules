/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:27:47 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/19 16:26:13 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const &other) : AMateria(other) {}

Ice	&Ice::operator=(Ice const &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {}

AMateria	*Ice::clone() const
{
	try
	{
		return new Ice(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << std::endl;
		return nullptr;
	}
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

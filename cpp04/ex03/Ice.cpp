/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:27:47 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/23 11:23:38 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice	&Ice::operator=(Ice const &other)
{
	std::cout << "Ice assignment operator called" << std::endl;	
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;	
}

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

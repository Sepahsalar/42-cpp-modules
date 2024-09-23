/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:27:16 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/23 11:21:51 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other) : _type(other._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &other)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const	&AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* General use member function called for " << target.getName() << " *" << std::endl;
}

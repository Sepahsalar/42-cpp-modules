/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:27:16 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/19 14:16:53 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &other) : _type(other._type) {}

AMateria	&AMateria::operator=(AMateria const &other)
{
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const	&AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "* General use member function called for " << target.getName() << " *" << std::endl;
	// (void)target;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:27:16 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 19:37:53 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(AMateria const &src) : _type(src._type) {}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

AMateria::~AMateria() {}

std::string const	&AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}

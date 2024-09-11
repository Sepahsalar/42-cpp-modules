/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:28:31 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &t) : type(t) {}

Weapon::~Weapon() {}

const std::string	&Weapon::getType() const
{
	return type;
}

void	Weapon::setType(const std::string &newType)
{
	type = newType;
}

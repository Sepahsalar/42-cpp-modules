/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:19:05 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/17 17:20:52 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: FragTrap(), ScavTrap(), _name("defaultDiamond")
{
	ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " created with default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
	: FragTrap(name), ScavTrap(name), _name(name)
{
	ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: FragTrap(other), ScavTrap(other), _name(other._name)
{
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "DiamondTrap " << _name << " copied." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		_name = other._name;
		ClapTrap::_name = _name + "_clap_name";
	}
	std::cout << "DiamondTrap " << _name << " assigned." << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destructed." << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	// int	temp = ScavTrap::_attackDamage;

	// ScavTrap::_attackDamage = DiamondTrap::_attackDamage;
	ScavTrap::attack(target);
	// ScavTrap::_attackDamage = temp;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}

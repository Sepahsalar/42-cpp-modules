/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:42:47 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/17 16:37:10 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = "defaultScav";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created with default constructor." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copied." << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap " << _name << " assigned." << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructed." << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " wants to attack " << target;
		std::cout << ", but has no hit or energy points left to attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ScavTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " has entered Gate Keeper mode!" << std::endl;
}

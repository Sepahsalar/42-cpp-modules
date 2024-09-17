/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:41:07 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/17 16:37:50 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "defaultFrag";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created with default constructor." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copied." << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name << " assigned." << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructed." << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " wants to attack " << target;
		std::cout << ", but has no hit or energy points left to attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:19:05 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : FragTrap(), ScavTrap(), _name("defaultDiamond")
{
    FragTrap::_name = _name + "_clap_name";
	ScavTrap::_name = _name + "_clap_name";
    FragTrap::_hitPoints = 100; // FragTrap’s hit points
    ScavTrap::_energyPoints = 50; // ScavTrap’s energy points
    FragTrap::_attackDamage = 30; // FragTrap’s attack damage
    std::cout << "DiamondTrap " << _name << " created with default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : FragTrap(), ScavTrap(), _name(name)
{
    FragTrap::_name = _name + "_clap_name";
	ScavTrap::_name = _name + "_clap_name";
    FragTrap::_hitPoints = 100; // FragTrap’s hit points
    ScavTrap::_energyPoints = 50; // ScavTrap’s energy points
    FragTrap::_attackDamage = 30; // FragTrap’s attack damage
    std::cout << "DiamondTrap " << _name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : FragTrap(other), ScavTrap(other), _name(other._name)
{
    FragTrap::_name = _name + "_clap_name";
	ScavTrap::_name = _name + "_clap_name";
    std::cout << "DiamondTrap " << _name << " copied." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    if (this != &other)
    {
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
        FragTrap::_name = _name + "_clap_name";
		ScavTrap::_name = _name + "_clap_name";
    }
    std::cout << "DiamondTrap " << _name << " assigned." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destructed." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target); // Use ScavTrap's attack method
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " << ScavTrap::_name << "." << std::endl;
}

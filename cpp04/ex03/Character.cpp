/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:28:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Unnamed")
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = nullptr;
	// std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = nullptr;
	// std::cout << "Character parameterized constructor called" << std::endl;
}

Character::Character(const Character &other)
{
	*this = other;
	// std::cout << "Character copy constructor called" << std::endl;
}

Character	&Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; ++i)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	// std::cout << "Character copy assignment operator called" << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		if (_inventory[i])
			delete _inventory[i];
	// std::cout << "Character destructor called" << std::endl;
}

std::string const	&Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			// std::cout << "Materia equipped in slot " << i << std::endl;
			return;
		}
	}
	// std::cout << "Inventory full, cannot equip more Materia!\n";
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		_inventory[idx] = nullptr;
		// std::cout << "Materia unequipped from slot " << idx << std::endl;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
	// else
	// 	std::cout << "No Materia in slot " << idx << std::endl;
}

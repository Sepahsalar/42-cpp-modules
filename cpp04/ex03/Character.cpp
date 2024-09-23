/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:28:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/23 11:40:16 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
	std::cout << "Character parameterized constructor called" << std::endl;
}

Character::Character(Character const &other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character	&Character::operator=(Character const &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	std::cout << "Character copy assignment operator called" << std::endl;
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = nullptr;
	}
	std::cout << "Character destructor called" << std::endl;
}

std::string const	&Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "Materia equipped in slot " << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot equip more Materia!" << std::endl;
	delete m;
}

void	Character::unequip(int idx)
{
	if (!_inventory[idx])
		return;
	if (idx >= 0 && idx < 4)
	{
		_inventory[idx] = nullptr;
		std::cout << "Materia unequipped from slot " << idx << std::endl;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Materia not found in slot " << idx << std::endl;
}

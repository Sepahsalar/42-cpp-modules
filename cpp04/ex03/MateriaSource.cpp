/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:30:16 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/23 11:34:11 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_templates[i] = nullptr;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = nullptr;
	}
	std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_templates[i])
				delete _templates[i];
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = nullptr;
		}
	}
	std::cout << "MateriaSource assignment operator called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i])
			delete _templates[i];
		_templates[i] = nullptr;
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_templates[i])
		{
			_templates[i] = m;
			std::cout << "Materia learned in slot " << i << std::endl;
			return;
		}
	}
	delete m;
	std::cout << "Inventory full, cannot learn more Materia!" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] && _templates[i]->getType().compare(type) == 0)
		{
			std::cout << "Materia is being created for slot " << i << std::endl;
			return _templates[i]->clone();
		}
	}
	std::cout << "Materia not found to be created" << std::endl;
	return nullptr;
}

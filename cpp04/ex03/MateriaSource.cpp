/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:30:16 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/19 14:53:08 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_templates[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < 4; ++i)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = nullptr;
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (_templates[i])
				delete _templates[i];
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = nullptr;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i])
			delete _templates[i];
		_templates[i] = nullptr;
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!_templates[i])
		{
			_templates[i] = m;
			return;
		}
	}
	delete m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return nullptr;
}

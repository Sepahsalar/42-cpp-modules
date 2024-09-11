/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:30:16 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_templates[i] = nullptr;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src._templates[i])
			_templates[i] = src._templates[i]->clone();
		else
			_templates[i] = nullptr;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		delete _templates[i];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete _templates[i];
			if (rhs._templates[i])
				_templates[i] = rhs._templates[i]->clone();
			else
				_templates[i] = nullptr;
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_templates[i] == nullptr)
		{
			_templates[i] = m;
			break;
		}
	}
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

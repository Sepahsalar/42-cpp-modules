/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:30 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 18:45:21 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog copied" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << "Dog assigned" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destroyed" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

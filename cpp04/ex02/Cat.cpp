/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:47 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 18:45:13 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
    this->_brain = new Brain(*other._brain);
    std::cout << "Cat copied" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
    if (this != &other)
	{
        this->type = other.type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat()
{
	delete this->_brain;
    std::cout << "Cat destroyed" << std::endl;
}

void	Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

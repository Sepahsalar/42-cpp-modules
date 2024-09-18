/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:47 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/18 17:07:12 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;
    std::cout << "Cat copied" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed" << std::endl;
}

void	Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

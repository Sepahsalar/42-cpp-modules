/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "++++++++++++++++" << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << "****************" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "----------------" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "++++++++++++++++" << std::endl;
	const WrongAnimal*	wrongMeta = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << "****************" << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << "----------------" << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}

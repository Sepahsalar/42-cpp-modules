/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/19 16:36:11 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "Testing Dog and Cat:" << std::endl;
	std::cout << std::endl;
	const AAnimal	*dog = new Dog();
	const AAnimal	*cat = new Cat();

	std::cout << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;

	std::cout << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;
	delete dog;
	delete cat;

	std::cout << std::endl << "Testing array of AAnimals (Dog and Cat):" << std::endl;
	std::cout << std::endl;
	AAnimal	*animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	std::cout << std::endl;
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	std::cout << std::endl;
	for (int k = 0; k < 4; k++)
	{
		animals[k]->makeSound();
		delete animals[k];
		if (k != 3)
			std::cout << std::endl;
	}

	// const AAnimal	*animal = new AAnimal();
	// AAnimal			animal;

	return 0;
}

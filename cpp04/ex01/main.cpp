/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 18:34:01 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "-----Animal tests-----" << std::endl;
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << std::endl;
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;

	delete dog;
	delete cat;

	std::cout << std::endl << "-----Array tests-----" << std::endl;
	Animal	*animals[4];
	for (int i = 0; i < 2; ++i)
		animals[i] = new Dog();
	std::cout << std::endl;
	for (int j = 2; j < 4; ++j)
		animals[j] = new Cat();
	std::cout << std::endl;
	for (int k = 0; k < 4; ++k)
		delete animals[k];

	std::cout << std::endl << "-----Copy tests-----" << std::endl;
	Dog	dog1;
	Dog	dog2 = dog1;
	std::cout << std::endl;
	dog2.makeSound();
	std::cout << std::endl;

	Cat	cat1;
	Cat	cat2;
	cat2 = cat1;
	std::cout << std::endl;
	cat2.makeSound();
	std::cout << std::endl;
	
	return 0;
}

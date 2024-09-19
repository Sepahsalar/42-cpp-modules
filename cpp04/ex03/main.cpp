/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/19 17:21:32 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "Test 1: Basic Materia Creation and Usage" << std::endl;
	IMateriaSource	*src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");
	AMateria	*tmp0 = src->createMateria("ice");
	me->equip(tmp0);
	AMateria	*tmp1 = src->createMateria("cure");
	me->equip(tmp1);

	ICharacter	*bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << "Test 2: Creating Unknown Materia" << std::endl;
	
	AMateria	*tmp2 = src->createMateria("fire");
	if (!tmp2)
		std::cout << "Cannot create Materia of type 'fire'!" << std::endl;
	else
		delete tmp2;

	std::cout << std::endl;

	std::cout << "Test 3: Equip more than 4 Materias" << std::endl;
	me->equip(new Ice());
	me->equip(new Cure());
	me->equip(new Cure());
	std::cout << std::endl;

	std::cout << "Test 4: Unequip Materia and Use Empty Slots" << std::endl;
	me->unequip(0);
	delete tmp0;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	std::cout << "Test 5: Deep Copy of Character" << std::endl;
	Character	*cloneMe = new Character(*dynamic_cast<Character *>(me));
	cloneMe->use(0, *bob);
	cloneMe->use(1, *bob);

	delete bob;
	delete src;
	delete me;
	delete cloneMe;

	return 0;
}

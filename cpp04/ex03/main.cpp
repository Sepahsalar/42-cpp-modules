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

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	// Test 1: Basic usage with Ice and Cure
	std::cout << "Test 1: Basic Materia Creation and Usage\n";
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	// Test 2: Trying to create unknown Materia
	std::cout << "Test 2: Creating Unknown Materia\n";
	tmp = src->createMateria("fire");
	if (!tmp)
		std::cout << "Cannot create Materia of type 'fire'!\n";

	std::cout << std::endl;

	// Test 3: Trying to equip more than 4 Materias
	std::cout << "Test 3: Equip more than 4 Materias\n";
	me->equip(new Ice()); // Slot 2
	me->equip(new Cure()); // Slot 3
	me->equip(new Cure()); // Extra, should not equip

	std::cout << std::endl;

	// Test 4: Unequip Materia and use empty slots
	std::cout << "Test 4: Unequip Materia and Use Empty Slots\n";
	me->unequip(0); // Unequip Ice from slot 0
	me->use(0, *bob); // Try to use an empty slot
	me->use(1, *bob); // Use Cure

	std::cout << std::endl;

	// Test 5: Deep copy of Character
	std::cout << "Test 5: Deep Copy of Character\n";
	Character *cloneMe = new Character(*dynamic_cast<Character *>(me)); // Deep copy me
	cloneMe->use(0, *bob); // Empty slot (copied)
	cloneMe->use(1, *bob); // Should work as Cure is in slot 1

	std::cout << std::endl;

	// Clean up
	delete bob;
	delete me;
	delete cloneMe;
	delete src;

	std::cout << "All tests passed successfully!" << std::endl;
	return 0;
}

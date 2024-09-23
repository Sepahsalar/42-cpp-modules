/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/23 11:51:18 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	std::cout << "** Test 1: Basic Materia Creation and Usage" << std::endl;
	IMateriaSource	*src = new MateriaSource();
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	ICharacter	*me = new Character("me");
	std::cout << std::endl;
	AMateria	*tmp0 = src->createMateria("ice");
	std::cout << std::endl;
	me->equip(tmp0);
	std::cout << std::endl;
	AMateria	*tmp1 = src->createMateria("cure");
	std::cout << std::endl;
	me->equip(tmp1);
	std::cout << std::endl;
	ICharacter	*bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << "** Test 2: Creating Unknown Materia" << std::endl;
	
	AMateria	*tmp2 = src->createMateria("fire");
	if (!tmp2)
		std::cout << "Cannot create Materia of type 'fire'!" << std::endl;
	else
		delete tmp2;

	std::cout << std::endl;

	std::cout << "** Test 3: Equip more than 4 Materias" << std::endl;
	me->equip(new Ice());
	std::cout << std::endl;
	me->equip(new Cure());
	std::cout << std::endl;
	me->equip(new Cure());
	std::cout << std::endl;

	std::cout << "** Test 4: Unequip Materia" << std::endl;
	me->unequip(0);
	std::cout << std::endl;
	delete tmp0;
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << std::endl;

	std::cout << "** Test 5: Deep Copy of Character" << std::endl;
	Character	*cloneMe = new Character(*dynamic_cast<Character *>(me));
	std::cout << std::endl;
	cloneMe->use(0, *bob);
	cloneMe->use(1, *bob);
	cloneMe->use(2, *bob);
	cloneMe->use(3, *bob);
	std::cout << std::endl << "-----------------------------------" << std::endl;
	std::cout << "** Deleting all objects" << std::endl;
	delete src;
	std::cout << std::endl;
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete cloneMe;

	return 0;
}

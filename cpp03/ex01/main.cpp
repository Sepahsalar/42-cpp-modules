/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/17 16:32:18 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	std::cout << "--- Creating ClapTrap ---" << std::endl;
	ClapTrap	clap1("Clappy");
	clap1.attack("Target1");
	clap1.takeDamage(3);
	clap1.beRepaired(5);

	std::cout << std::endl << "--- Creating ScavTrap ---" << std::endl;
	ScavTrap scav1("Scavvy");
	scav1.attack("Target2");
	scav1.takeDamage(40);
	scav1.beRepaired(30);
	std::cout << std::endl;
	scav1.guardGate();

	std::cout << std::endl << "--- Testing Energy Depletion in ScavTrap ---" << std::endl;
	for (int i = 0; i < 50; ++i)
		scav1.attack("EnergyDepletionTarget");

	std::cout << std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/17 16:43:56 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	clap("Clappy");
	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(10);

	std::cout << std::endl;
	ScavTrap	scav("Scavvy");
	scav.attack("Target2");
	scav.takeDamage(10);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << std::endl;
	FragTrap	frag("Fraggy");
	frag.attack("Target3");
	frag.takeDamage(20);
	frag.beRepaired(30);
	frag.highFivesGuys();

	std::cout << std::endl;
	ClapTrap	defaultClap;
	ScavTrap	defaultScav;
	FragTrap	defaultFrag;

	std::cout << std::endl;
	defaultClap.attack("Target4");
	defaultScav.attack("Target5");
	defaultFrag.attack("Target6");
	defaultFrag.highFivesGuys();

	std::cout << std::endl;

	return 0;
}


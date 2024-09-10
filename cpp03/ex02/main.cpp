/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 16:07:20 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	clap("Clapster");
	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(10);

	std::cout << std::endl;
	ScavTrap	scav("Scavster");
	scav.attack("Target2");
	scav.takeDamage(10);
	scav.beRepaired(20);
	scav.guardGate();

	std::cout << std::endl;
	FragTrap	frag("Fragster");
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


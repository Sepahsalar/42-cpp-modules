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

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	clap1;
	ClapTrap	clap2("Clappy");
	ClapTrap	clap3(clap2);
	ClapTrap	clap4;
	ClapTrap	clap5("NoEnergyClap");

	clap4 = clap3;

	std::cout << std::endl << "--- Test Attack ---" << std::endl;
	clap2.attack("Target1");

	std::cout  << std::endl << "--- Test Take Damage ---"  << std::endl;
	clap2.takeDamage(3);
	clap2.takeDamage(8);

	std::cout  << std::endl << "--- Test Repair ---" << std::endl;
	clap2.beRepaired(5);
	clap2.beRepaired(7);

	std::cout  << std::endl << "--- Test No Energy/HP for Actions ---"  << std::endl;
	for (int i = 0; i < 10; i++)
		clap5.attack("Target2");
	std::cout << std::endl;
	clap5.attack("Target3");
	clap5.takeDamage(20);
	clap5.beRepaired(5);
	std::cout << std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/18 13:47:45 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	std::cout << "************" << std::endl;
	DiamondTrap	dt1("Diamond1");
	std::cout << std::endl;
	dt1.attack("target1");
	dt1.takeDamage(10);
	dt1.beRepaired(5);
	dt1.guardGate();

	std::cout << std::endl;
	std::cout << "************" << std::endl;
	DiamondTrap	dt2("Diamond2");
	std::cout << std::endl;
	dt2.attack("target2");
	dt2.takeDamage(20);
	dt2.beRepaired(10);
	dt2.highFivesGuys();

	std::cout << std::endl;
	std::cout << "************" << std::endl;
	DiamondTrap	dt3(dt1);
	std::cout << std::endl;
	dt3.attack("target3");
	dt3.takeDamage(30);
	dt3.beRepaired(15);

	std::cout << std::endl;
	std::cout << "************" << std::endl;
	dt1.whoAmI();
	dt2.whoAmI();
	dt3.whoAmI();

	std::cout << std::endl;
	std::cout << "************" << std::endl;
	return 0;
}

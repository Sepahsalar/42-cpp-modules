/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/17 16:57:25 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	dt1("Diamond1");
	DiamondTrap	dt2("Diamond2");
	DiamondTrap	dt3(dt1);

	std::cout << std::endl;
	dt1.attack("target1");
	dt1.takeDamage(10);
	dt1.beRepaired(5);

	std::cout << std::endl;
	dt2.attack("target2");
	dt2.takeDamage(20);
	dt2.beRepaired(10);

	std::cout << std::endl;
	dt3.attack("target3");
	dt3.takeDamage(30);
	dt3.beRepaired(15);

	std::cout << std::endl;
	dt1.whoAmI();
	dt2.whoAmI();
	dt3.whoAmI();

	std::cout << std::endl;
	return 0;
}

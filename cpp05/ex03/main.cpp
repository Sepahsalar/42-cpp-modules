/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:09:19 by asohrabi          #+#    #+#             */
/*   Updated: 2025/04/16 17:30:56 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Intern	someIntern;

	AForm	*f1 = someIntern.makeForm("shrubbery creation", "garden");
	AForm	*f2 = someIntern.makeForm("robotomy request", "R2D2");
	AForm	*f3 = someIntern.makeForm("presidential pardon", "Neo");
	AForm	*f4 = someIntern.makeForm("coffee brewing", "breakroom");

	std::cout << "---Executing Forms---" << std::endl;

	Bureaucrat	boss("Boss", 1);

	if (f1)
	{
		boss.signForm(*f1);
		std::cout << std::endl;
		boss.executeForm(*f1);
		delete f1;
	}

	std::cout << std::endl;
	if (f2)
	{
		boss.signForm(*f2);
		std::cout << std::endl;
		boss.executeForm(*f2);
		delete f2;
	}

	std::cout << std::endl;
	if (f3)
	{
		boss.signForm(*f3);
		std::cout << std::endl;
		boss.executeForm(*f3);
		delete f3;
	}

	delete f4;
	return 0;
}

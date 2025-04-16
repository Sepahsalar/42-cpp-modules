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
	Intern someIntern;

	AForm *f1 = someIntern.makeForm("shrubbery creation", "garden");
	AForm *f2 = someIntern.makeForm("robotomy request", "R2D2");
	AForm *f3 = someIntern.makeForm("presidential pardon", "Neo");
	AForm *f4 = someIntern.makeForm("coffee brewing", "breakroom");

	Bureaucrat boss("Boss", 1);

	if (f1)
	{
		boss.signForm(*f1);
		boss.executeForm(*f1);
		delete f1;
	}

	if (f2)
	{
		boss.signForm(*f2);
		boss.executeForm(*f2);
		delete f2;
	}

	if (f3)
	{
		boss.signForm(*f3);
		boss.executeForm(*f3);
		delete f3;
	}

	delete f4; // nullptr is safe to delete
	return 0;
}

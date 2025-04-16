/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:09:19 by asohrabi          #+#    #+#             */
/*   Updated: 2025/04/16 17:17:56 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 140);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Marvin");
		PresidentialPardonForm pardon("Ford");

		// Try signing forms
		bob.signForm(shrub);
		alice.signForm(shrub);
		alice.signForm(robo);
		alice.signForm(pardon);

		// Try executing forms
		bob.executeForm(shrub); // Should fail if bob is too low
		alice.executeForm(shrub);
		alice.executeForm(robo);
		alice.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

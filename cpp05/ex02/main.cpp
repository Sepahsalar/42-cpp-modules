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

int	main()
{
	try
	{
		Bureaucrat				alice("Alice", 1);
		Bureaucrat				bob("Bob", 146);
		Bureaucrat				tom("Tom", 75);
		Bureaucrat				jerry("Jerry", 30);

		ShrubberyCreationForm	shrub("Garden");
		RobotomyRequestForm		robo("Marvin");
		PresidentialPardonForm	pardon("Ford");

		std::cout << "--- Signing Forms ---" << std::endl;
		bob.signForm(shrub);   // Should fail
		alice.signForm(shrub); // Should succeed
		tom.signForm(robo);    // Should fail
		jerry.signForm(robo);  // Should succeed
		jerry.signForm(pardon); // Should succeed
		alice.signForm(pardon);// Should succeed

		std::cout << std::endl << "--- Executing Forms ---" << std::endl;
		bob.executeForm(shrub);    // Should fail (too low)
		std::cout << std::endl;
		alice.executeForm(shrub);  // Should succeed

		std::cout << std::endl;
		tom.executeForm(robo);     // Should fail (signed but low grade)
		std::cout << std::endl;
		jerry.executeForm(robo);   // Should succeed (50% success)

		std::cout << std::endl;
		jerry.executeForm(pardon); // Should fail (signed but grade too low)
		std::cout << std::endl;
		alice.executeForm(pardon); // Should succeed

		std::cout << std::endl << "--- Executing Unsigned Form ---" << std::endl;
		PresidentialPardonForm	unSignedForm("Zaphod");

		alice.executeForm(unSignedForm); // Should throw NotSignedException
	}
	catch (std::exception &e)
	{
		std::cerr << "Unexpected Exception: " << e.what() << std::endl;
	}

	return 0;
}

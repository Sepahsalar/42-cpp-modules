/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:09:19 by asohrabi          #+#    #+#             */
/*   Updated: 2025/04/14 21:27:23 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	alice("Alice", 2);

		std::cout << alice << std::endl;

		alice.incrementGrade();
		std::cout << "After promotion: " << alice << std::endl;

		alice.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	try
	{
		Bureaucrat	bob("Bob", 149);

		std::cout << bob << std::endl;

		bob.decrementGrade();
		std::cout << "After demotion: " << bob << std::endl;

		bob.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	try
	{
		Bureaucrat	error("ErrorGuy", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception during construction: " << e.what() << std::endl;
	}

	return 0;
}

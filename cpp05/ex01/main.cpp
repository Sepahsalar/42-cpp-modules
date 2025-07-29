/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:09:19 by asohrabi          #+#    #+#             */
/*   Updated: 2025/04/16 16:46:00 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	alice("Alice", 30);
		Bureaucrat	bob("Bob", 100);

		Form		leaveRequest("LeaveRequest", 50, 30);

		std::cout << leaveRequest << std::endl;

		alice.signForm(leaveRequest);
		std::cout << leaveRequest << std::endl;

		bob.signForm(leaveRequest);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	try
	{
		Form	invalidForm("InvalidForm", 0, 10);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Construction error: " << e.what() << std::endl;
	}

	return 0;
}

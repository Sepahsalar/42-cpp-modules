/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:53:37 by asohrabi          #+#    #+#             */
/*   Updated: 2025/04/16 17:23:37 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
// #include <iostream>


RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand(std::time(nullptr));
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "🔧 Bzzt... Vrrrrrr... 🔧\n";
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed on " << _target << "!\n";
}

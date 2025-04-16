/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:28:16 by asohrabi          #+#    #+#             */
/*   Updated: 2025/04/16 17:31:51 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Define static creator functions
static AForm *createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

Intern::Intern() {}
Intern::Intern(const Intern &) {}
Intern &Intern::operator=(const Intern &) { return *this; }
Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};

	typedef AForm *(*FormCreator)(const std::string &);
	FormCreator creators[] = {
		createShrubbery,
		createRobotomy,
		createPresidential};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cerr << "Intern couldn't find the form: " << formName << std::endl;
	return nullptr;
}

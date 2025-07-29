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

Intern::Intern() {}

Intern::Intern(const Intern &) {}

Intern	&Intern::operator=(const Intern &)
{
	return *this;
}

Intern::~Intern() {}


static AForm	*createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresidential(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};


	FormCreator creators[] = {
		createShrubbery,
		createRobotomy,
		createPresidential};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i])
		{
			try
			{
				AForm	*form = creators[i](target);

				std::cout << "Intern creates " << formName << std::endl;
				return form;
			}
			catch(const std::exception& e)
			{
				std::cerr << "Failed to create form: " << e.what() << std::endl;
				return nullptr;
			}
		}
	}

	std::cerr << "Intern couldn't find the form: " << formName << std::endl;
	return nullptr;
}

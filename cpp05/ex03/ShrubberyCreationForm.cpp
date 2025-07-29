/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:52:55 by asohrabi          #+#    #+#             */
/*   Updated: 2025/04/16 17:23:07 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	file(_target + "_shrubbery");

	if (!file)
		throw std::runtime_error("Failed to create file: " + _target + "_shrubbery");

	if (!file.is_open())
		throw std::runtime_error("Failed to open file for writing: " + _target + "_shrubbery");
	else
	{
		file << "      🌲" << std::endl;
		file << "     🌳🌳" << std::endl;
		file << "    🌲🌲🌲" << std::endl;
		file << "   🌳🌳🌳🌳" << std::endl;
		file << "  🌲🌲🌲🌲🌲" << std::endl;
		file << "     |||||" << std::endl;
		file.close();
		std::cout << "Shrubbery created: " << _target << "_shrubbery" << std::endl;
	}
}

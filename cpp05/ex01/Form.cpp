/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:31:20 by asohrabi          #+#    #+#             */
/*   Updated: 2025/04/14 21:32:20 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute) {}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		// _name, _gradeToSign, and _gradeToExecute are const, so we cannot assign them here.
	}
	return *this;
}

Form::~Form() {}

const	std::string &Form::getName() const
{
	return _name;
}

bool	Form::getIsSigned() const
{
	return _isSigned;
}

int	Form::getGradeToSign() const
{
	return _gradeToSign;
}

int	Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char	*Form::GradeTooHighException::what() const noexcept
{
	return "Form grade is too high!";
}

const char	*Form::GradeTooLowException::what() const noexcept
{
	return "Form grade is too low!";
}

std::ostream	&operator<<(std::ostream &out, const Form &f)
{
	out << "Form '" << f.getName() << "', signed: " << std::boolalpha << f.getIsSigned()
		<< ", grade required to sign: " << f.getGradeToSign()
		<< ", grade required to execute: " << f.getGradeToExecute() << ".";
	return out;
}

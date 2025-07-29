/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:53:02 by asohrabi          #+#    #+#             */
/*   Updated: 2025/04/16 17:22:16 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm				&operator=(const AForm &other);
		virtual				~AForm();

		const std::string	&getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(const Bureaucrat &bureaucrat);
		void				execute(Bureaucrat const &executor) const;
		virtual void		executeAction() const = 0;

		class GradeTooHighException : public std::exception
		{
			const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			const char *what() const noexcept override;
		};

		class NotSignedException : public std::exception
		{
			const char *what() const noexcept override;
		};
};

std::ostream				&operator<<(std::ostream &out, const AForm &form);

#endif

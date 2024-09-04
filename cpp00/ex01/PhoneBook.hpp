/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:37:30 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/04 19:31:22 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search() const;
		void	displayContact(int index) const;

	private:
		Contact	_contacts[8];
		int		_currentIndex;
		int		_totalContacts;

		std::string	_truncate(const std::string &str) const;
};

#endif

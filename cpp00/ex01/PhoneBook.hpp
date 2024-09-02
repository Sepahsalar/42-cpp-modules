/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:37:30 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/02 18:55:53 by asohrabi         ###   ########.fr       */
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

		void add_contact();
		void display_contacts() const;
		void display_contact(int index) const;

	private:
		Contact	contacts[8];
		int		current_index;
		int		total_contacts;

		std::string truncate(const std::string &str) const;
};

#endif

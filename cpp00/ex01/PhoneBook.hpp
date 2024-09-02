/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:37:30 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/02 16:43:41 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

class PhoneBook {
public:
    PhoneBook();
	~PhoneBook();
    void addContact(const Contact& contact);
    void displayContacts() const;
    void displayContact(int index) const;

private:
    Contact contacts[8];
    int current_index;
    int total_contacts;

    std::string truncate(const std::string& str) const;
};

#endif

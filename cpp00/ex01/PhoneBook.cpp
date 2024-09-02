/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:37:51 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/02 16:49:34 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : current_index(0), total_contacts(0) {}

void PhoneBook::addContact(const Contact& contact) {
	contacts[current_index] = contact;
	current_index = (current_index + 1) % 8;
	if (total_contacts < 8) {
		++total_contacts;
	}
}

PhoneBook::~PhoneBook() {}

void PhoneBook::displayContacts() const {
	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::string(44, '-') << std::endl;
	for (int i = 0; i < total_contacts; ++i) {
		std::cout << "|" << std::setw(10) << i << "|"
				<< std::setw(10) << truncate(contacts[i].first_name) << "|"
				<< std::setw(10) << truncate(contacts[i].last_name) << "|"
				<< std::setw(10) << truncate(contacts[i].nickname) << "|" << std::endl;
	}
}

void PhoneBook::displayContact(int index) const {
	if (index >= 0 && index < total_contacts) {
		std::cout << "First Name: " << contacts[index].first_name << std::endl
				<< "Last Name: " << contacts[index].last_name << std::endl
				<< "Nickname: " << contacts[index].nickname << std::endl
				<< "Phone Number: " << contacts[index].phone_number << std::endl
				<< "Darkest Secret: " << contacts[index].darkest_secret << std::endl;
	} else {
		std::cout << "Invalid index!" << std::endl;
	}
}

std::string PhoneBook::truncate(const std::string& str) const {
	if (str.size() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

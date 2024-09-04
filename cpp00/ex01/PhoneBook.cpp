/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:37:51 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/04 13:05:26 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _currentIndex(0), _totalContacts(0) {}

PhoneBook::~PhoneBook() {}

std::string get_valid_input(const std::string &prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);	
		if (input.empty())
			std::cout << "Error: Input should contain something. Please try again." << std::endl;
		else
			return input;
	}
}

void PhoneBook::add()
{
	std::string first_name = get_valid_input("Enter First Name: ");
    std::string last_name = get_valid_input("Enter Last Name: ");
    std::string nickname = get_valid_input("Enter Nickname: ");
    std::string phone_number = get_valid_input("Enter Phone Number: ");
    std::string darkest_secret = get_valid_input("Enter Darkest Secret: ");

	Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	_contacts[_currentIndex] = new_contact;
	_currentIndex = (_currentIndex + 1) % 8;
	if (_totalContacts < 8)
		_totalContacts++;
}

void PhoneBook::search() const
{
	int			index;
	std::string	input;
	bool		valid = true;

	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	for (index = 0; index < _totalContacts; index++)
	{
		std::cout << "|" << std::setw(10) << index + 1 << "|"
				<< std::setw(10) << _truncate(_contacts[index].get_first_name()) << "|"
				<< std::setw(10) << _truncate(_contacts[index].get_last_name()) << "|"
				<< std::setw(10) << _truncate(_contacts[index].get_nickname()) << "|" << std::endl;
	}
	if (_totalContacts > 0)
	{
		std::cout << "Enter the index of the contact to display: ";
		std::getline(std::cin, input);
        for (char c : input)
		{
            if (!std::isdigit(c))
			{
                valid = false;
                break;
            }
        }
		std::stringstream ss(input);
		if (valid && ss >> index && ss.eof()
			&& index > 0 && index <= _totalContacts)
            displayContact(index - 1);
        else
            std::cout << "Error: Invalid index." << std::endl;
	}
}

void PhoneBook::displayContact(int index) const
{
	std::cout << "First Name: " << _contacts[index].get_first_name() << std::endl
			<< "Last Name: " << _contacts[index].get_last_name() << std::endl
			<< "Nickname: " << _contacts[index].get_nickname() << std::endl
			<< "Phone Number: " << _contacts[index].get_phone_number() << std::endl
			<< "Darkest Secret: " << _contacts[index].get_darkest_secret() << std::endl;
}

std::string PhoneBook::_truncate(const std::string &str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

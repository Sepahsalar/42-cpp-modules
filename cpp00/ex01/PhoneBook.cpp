/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:37:51 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/04 19:37:58 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _currentIndex(0), _totalContacts(0) {}

PhoneBook::~PhoneBook() {}

std::string	get_valid_input(const std::string &prompt)
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

void	PhoneBook::add()
{
	std::string _firstName = get_valid_input("Enter First Name: ");
    std::string _lastName = get_valid_input("Enter Last Name: ");
    std::string _nickname = get_valid_input("Enter Nickname: ");
    std::string _phoneNumber = get_valid_input("Enter Phone Number: ");
    std::string _darkestSecret = get_valid_input("Enter Darkest Secret: ");

	Contact new_contact(_firstName, _lastName, _nickname, _phoneNumber, _darkestSecret);
	_contacts[_currentIndex] = new_contact;
	_currentIndex = (_currentIndex + 1) % 8;
	if (_totalContacts < 8)
		_totalContacts++;
}

void	PhoneBook::search() const
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
				<< std::setw(10) << _truncate(_contacts[index].getFirstName()) << "|"
				<< std::setw(10) << _truncate(_contacts[index].getLastName()) << "|"
				<< std::setw(10) << _truncate(_contacts[index].getNickname()) << "|" << std::endl;
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

void	PhoneBook::displayContact(int index) const
{
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl
			<< "Last Name: " << _contacts[index].getLastName() << std::endl
			<< "Nickname: " << _contacts[index].getNickname() << std::endl
			<< "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl
			<< "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

std::string	PhoneBook::_truncate(const std::string &str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

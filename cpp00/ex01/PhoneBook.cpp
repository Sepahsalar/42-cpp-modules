/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:37:51 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/02 19:06:37 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : current_index(0), total_contacts(0) {}

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

void PhoneBook::add_contact()
{
	std::string first_name = get_valid_input("Enter First Name: ");
    std::string last_name = get_valid_input("Enter Last Name: ");
    std::string nickname = get_valid_input("Enter Nickname: ");
    std::string phone_number = get_valid_input("Enter Phone Number: ");
    std::string darkest_secret = get_valid_input("Enter Darkest Secret: ");

	Contact new_contact(first_name, last_name, nickname, phone_number, darkest_secret);
	contacts[current_index] = new_contact;
	current_index = (current_index + 1) % 8;
	if (total_contacts < 8)
		total_contacts++;
}

void PhoneBook::display_contacts() const
{
	int			index;
	std::string	input;
	bool		valid = true;

	std::cout << "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	for (index = 0; index < total_contacts; index++)
	{
		std::cout << "|" << std::setw(10) << index + 1 << "|"
				<< std::setw(10) << truncate(contacts[index].get_first_name()) << "|"
				<< std::setw(10) << truncate(contacts[index].get_last_name()) << "|"
				<< std::setw(10) << truncate(contacts[index].get_nickname()) << "|" << std::endl;
	}
	if (total_contacts > 0)
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
			&& index > 0 && index <= total_contacts)
            display_contact(index - 1);
        else
            std::cout << "Error: Invalid index." << std::endl;
	}
}

void PhoneBook::display_contact(int index) const
{
	std::cout << "First Name: " << contacts[index].get_first_name() << std::endl
			<< "Last Name: " << contacts[index].get_last_name() << std::endl
			<< "Nickname: " << contacts[index].get_nickname() << std::endl
			<< "Phone Number: " << contacts[index].get_phone_number() << std::endl
			<< "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}

std::string PhoneBook::truncate(const std::string &str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

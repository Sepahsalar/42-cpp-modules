/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:45 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/03 13:23:01 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
	while (true)
	{
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.displayContacts();
		else if (command == "EXIT")
			break;
	}
	return 0;
}

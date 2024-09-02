/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:45 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/02 18:27:53 by asohrabi         ###   ########.fr       */
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
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.display_contacts();
		else if (command == "EXIT")
			break;
	}
	return 0;
}

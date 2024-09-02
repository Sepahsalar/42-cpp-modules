/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:45 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/02 16:42:06 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void addContact(PhoneBook& phonebook) {
    std::string first_name, last_name, nickname, phone_number, darkest_secret;

    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);

    if (!first_name.empty() && !last_name.empty() && !nickname.empty() && !phone_number.empty() && !darkest_secret.empty()) {
        phonebook.addContact(Contact(first_name, last_name, nickname, phone_number, darkest_secret));
        std::cout << "Contact added successfully.\n";
    } else {
        std::cout << "All fields are required!\n";
    }
}

void searchContact(const PhoneBook& phonebook) {
    phonebook.displayContacts();
    std::cout << "Enter the index of the contact to display: ";
    int index;
    std::cin >> index;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear input buffer
    phonebook.displayContact(index);
}

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            addContact(phonebook);
        } else if (command == "SEARCH") {
            searchContact(phonebook);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT.\n";
        }
    }

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/04 23:43:30 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Address of string      : " << &string << std::endl;
	std::cout << "Address -> by pointer  : " << stringPTR << std::endl;
	std::cout << "Address -> by reference: " << &stringREF << std::endl;
	
	std::cout << "Value of string        : " << string << std::endl;
	std::cout << "Value -> by pointer    : " << *stringPTR << std::endl;
	std::cout << "Value -> by reference  : " << stringREF << std::endl;
	return 0;
}

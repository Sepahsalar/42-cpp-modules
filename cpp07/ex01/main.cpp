/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:06:05 by asohrabi          #+#    #+#             */
/*   Updated: 2025/08/01 13:15:58 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	int			numbers[] = {1, 2, 3};
	char		letters[] = {'a', 'b', 'c'};
	std::string	words[] = {"hi", "there"};

	std::cout << "=== Integers ===" << std::endl;
	iter(numbers, 3, increment<int>);

	std::cout << std::endl << "=== Characters ===" << std::endl;
	iter(letters, 3, toUpper<char>);

	std::cout << std::endl << "=== Strings ===" << std::endl;
	iter(words, 2, addExclamation<std::string>);

	std::cout << std::endl << "=== Empty array ===" << std::endl;
    int	emptyArray[0];

    iter(emptyArray, 0, increment<int>); // Should do nothing

	return 0;
}

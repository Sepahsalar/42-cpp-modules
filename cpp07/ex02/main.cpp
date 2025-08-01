/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:22:48 by asohrabi          #+#    #+#             */
/*   Updated: 2025/08/01 15:01:15 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

void	printArray(const Array<int> &arr)
{
	int	maxPrint = 10;
	
	if (arr.size() == 0)
	{
		std::cout << "Array is empty." << std::endl;
		return;
	}
	std::cout << "Array contents (first " << maxPrint << " elements): ";
	for (int i = 0; i < static_cast<int>(arr.size()) && i < maxPrint; ++i)
	{
		if (i > 0)
			std::cout << ", ";
		std::cout << arr[i];
	}
	std::cout << std::endl;
}

int	main()
{
	std::srand(static_cast<int>(std::time(NULL)));

	std::cout << "=== Constructing and filling Array<int> with " << MAX_VAL << " elements ===" << std::endl;
	Array<int>	numbers(MAX_VAL);
	int			*mirror = new int[MAX_VAL];

	for (int i = 0; i < MAX_VAL; i++)
	{
		int	value = std::rand();

		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << std::endl << "=== Printing a sample of the original numbers ===" << std::endl;
	printArray(numbers);

	std::cout << std::endl << "=== Testing copy constructor and assignment operator ===" << std::endl;
	{
		Array<int>	tmp;
		
		tmp = numbers;
	
		Array<int>	test(tmp);

		std::cout << "Copy constructor and assignment test passed (scoped)" << std::endl;
	}

	std::cout << std::endl << "=== Verifying content match with mirror array ===" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "Mismatch at index " << i << ": mirror = " << mirror[i]
					<< ", numbers = " << numbers[i] << std::endl;
			delete[] mirror;
			return 1;
		}
	}
	std::cout << "All values match!" << std::endl;

	std::cout << std::endl << "=== Testing out-of-bounds accesses ===" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception on negative index: " << e.what() << std::endl;
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception on MAX_VAL index: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Rewriting array with new random values ===" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = std::rand();
	}
	printArray(numbers);

	std::cout << std::endl << "=== Testing const operator[] ===" << std::endl;
	const Array<int>	constNumbers = numbers;
	printArray(constNumbers);

	std::cout << std::endl << "=== Testing default constructor (empty array) ===" << std::endl;
	Array<int>	emptyArray;

	std::cout << "Size of array: " << emptyArray.size() << std::endl;
	try
	{
		emptyArray[0] = 10;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Access on empty array: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== All tests passed ===" << std::endl;
	delete[] mirror;
	return 0;
}

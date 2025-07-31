/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 00:43:45 by asohrabi          #+#    #+#             */
/*   Updated: 2025/07/31 13:17:30 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <type_traits>

Base	*generate()
{
	std::srand(std::time(nullptr));
	int	r = std::rand() % 3;

	switch (r)
	{
		case 0:
			std::cout << "Generated: A" << std::endl;
			return new A;
		case 1:
			std::cout << "Generated: B" << std::endl;
			return new B;
		default:
			std::cout << "Generated: C" << std::endl;
			return new C;
	}
}

void	identify(Base *p)
{
	std::cout << "Type (ptr): ";
	if (p == nullptr)
	{
		std::cout << "Null pointer" << std::endl;
		return;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	std::cout << "Type (ref): ";
	
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (...)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}

int	main()
{
	Base	*obj = generate();

	identify(obj);     // Pointer version
	identify(*obj);    // Reference version

	delete obj;
	return 0;
}

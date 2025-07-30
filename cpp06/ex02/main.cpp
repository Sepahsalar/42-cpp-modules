/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 00:43:45 by asohrabi          #+#    #+#             */
/*   Updated: 2025/07/31 01:00:54 by asohrabi         ###   ########.fr       */
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
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int	r = std::rand() % 3;

	switch (r)
	{
		case 0:
			std::cout << "Generated: A\n";
			return new A;
		case 1:
			std::cout << "Generated: B\n";
			return new B;
		default:
			std::cout << "Generated: C\n";
			return new C;
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Type (ptr): A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type (ptr): B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type (ptr): C" << std::endl;
	else
		std::cout << "Type (ptr): Unknown" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Type (ref): A" << std::endl;
	}
	catch (...)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "Type (ref): B" << std::endl;
		}
		catch (...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "Type (ref): C" << std::endl;
			}
			catch (...)
			{
				std::cout << "Type (ref): Unknown" << std::endl;
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

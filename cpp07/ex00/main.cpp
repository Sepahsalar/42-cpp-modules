/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:36:22 by asohrabi          #+#    #+#             */
/*   Updated: 2025/08/01 12:45:32 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main() {
	std::cout << "=== Test with integers ===" << std::endl;
	int	a = 2;
	int	b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::cout << std::endl << "=== Test with strings ===" << std::endl;
	std::string	c = "chaine1";
	std::string	d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	std::cout << std::endl << "=== Test with equal values (int) ===" << std::endl;
	int	e = 5;
	int	f = 5;
	
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

	std::cout << std::endl << "=== Test with floats ===" << std::endl;
	float	g = 4.2f;
	float	h = 9.8f;
	
	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
	std::cout << "max(g, h) = " << ::max(g, h) << std::endl;

	return 0;
}

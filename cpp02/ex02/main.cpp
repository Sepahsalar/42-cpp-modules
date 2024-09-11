/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:36 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed const	c(42.42f);
	Fixed		d(10);
	
	std::cout << "Original Tests:" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl << "New Tests:" << std::endl;

	std::cout << std::endl << "Arithmetic Operations:" << std::endl;
	std::cout << "c + d: " << c + d << std::endl;
	std::cout << "c - d: " << c - d << std::endl;
	std::cout << "c * d: " << c * d << std::endl;
	std::cout << "c / d: " << c / d << std::endl;

	std::cout << std::endl << "Comparison Operations:" << std::endl;
	std::cout << "Is c > d ? " << (c > d) << std::endl;
	std::cout << "Is c < d ? " << (c < d) << std::endl;
	std::cout << "Is c >= d? " << (c >= d) << std::endl;
	std::cout << "Is c <= d? " << (c <= d) << std::endl;
	std::cout << "Is c == d? " << (c == d) << std::endl;
	std::cout << "Is c != d? " << (c != d) << std::endl;

	std::cout << std::endl << "Increment/Decrement Operations:" << std::endl;
	std::cout << "Original d          : " << d << std::endl;
	std::cout << "Pre-increment       : " << ++d << std::endl;
	std::cout << "Post-increment      : " << d++ << std::endl;
	std::cout << "After Post-increment: " << d << std::endl;
	std::cout << "Pre-decrement       : " << --d << std::endl;
	std::cout << "Post-decrement      : " << d-- << std::endl;
	std::cout << "After Post-decrement: " << d << std::endl;

	std::cout << std::endl << "Min/Max Operations:" << std::endl;
	std::cout << "Min of c and d: " << Fixed::min(c, d) << std::endl;
	std::cout << "Max of c and d: " << Fixed::max(c, d) << std::endl;
	
	return 0;
}

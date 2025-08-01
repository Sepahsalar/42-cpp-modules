/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:55:54 by asohrabi          #+#    #+#             */
/*   Updated: 2025/08/01 13:32:05 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <cstddef>

template <typename T>
void	iter(T *array, size_t length, void (*func)(T&))
{
	if (!array || !func)
		return ;

	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T>
void	increment(T& value)
{
	++value;
	std::cout << "Incremented: " << value << std::endl;
}

template <typename T>
void	toUpper(T &value)
{
	if (value >= 'a' && value <= 'z')
		value -= 32;

	std::cout << "ToUpper: " << value << std::endl;
}

template <typename T>
void	addExclamation(T &value)
{
	value += "!";
	std::cout << "Added !: " << value << std::endl;
}

#endif

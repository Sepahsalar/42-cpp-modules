/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:22:58 by asohrabi          #+#    #+#             */
/*   Updated: 2025/08/01 13:41:55 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T				*_data;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array			&operator=(const Array &other);
		~Array();

		T				&operator[](int index);
		const T			&operator[](int index) const;

		unsigned int	size() const;
};

#include "Array.tpp"

#endif

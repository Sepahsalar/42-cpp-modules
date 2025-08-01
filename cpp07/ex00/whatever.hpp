/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:36:12 by asohrabi          #+#    #+#             */
/*   Updated: 2025/08/01 13:33:03 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& a, T& b)
{
	T	temp = a;

	a = b;
	b = temp;
}

template <typename T>
const T&	min(const T& a, const T& b)
{
	return (a < b) ? a : b;
}

template <typename T>
const T&	max(const T& a, const T& b)
{
	return (a > b) ? a : b;
}

#endif

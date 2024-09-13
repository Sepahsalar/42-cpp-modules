/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:59:29 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/13 13:25:12 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &other);
		Fixed				&operator=(const Fixed &other);
		~Fixed();

		int					getRawBits() const;
		void				setRawBits(int const raw);
		int					toInt() const;
		float				toFloat() const;

	private:
		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream				&operator<<(std::ostream &out, const Fixed &fixed);

#endif

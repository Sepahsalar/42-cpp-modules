/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:57:04 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/05 20:12:58 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float x0, const float y0);
		Point(const Point &other);
		Point	&operator=(const Point &other);
		~Point();

		Fixed	getX() const;
		Fixed	getY() const;
	
	private:
		Fixed const	x;
		Fixed const	y;
};

#endif

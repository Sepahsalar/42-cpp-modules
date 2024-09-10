/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:57:32 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 16:07:20 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x0, const float y0) : x(x0), y(y0) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point	&Point::operator=(const Point &other)
{
	()other;
	return *this;
}

Point::~Point() {}

Fixed	Point::getX() const
{
	return x;
}

Fixed	Point::getY() const
{
	return y;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:57:25 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(Point const &p1, Point const &p2, Point const &p3)
{
	Fixed	x1 = p1.getX();
	Fixed	y1 = p1.getY();
	Fixed	x2 = p2.getX();
	Fixed	y2 = p2.getY();
	Fixed	x3 = p3.getX();
	Fixed	y3 = p3.getY();

	Fixed	area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / Fixed(2.0f);
	area = area < Fixed(0.0f) ? Fixed(0.0f) - area : area;

	return area;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea = area(a, b, c);
	Fixed	area1 = area(point, b, c);
	Fixed	area2 = area(a, point, c);
	Fixed	area3 = area(a, b, point);

	if (area1 > Fixed(0.0f) && area2 > Fixed(0.0f) && area3 > Fixed(0.0f)
		&& totalArea == area1 + area2 + area3)
		return true;
	return false;
}

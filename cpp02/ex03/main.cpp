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

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point a(0.0f, 0.0f);
	Point b(5.0f, 0.0f);
	Point c(0.0f, 5.0f);

	// Test point inside the triangle
	Point inside(2.5f, 2.0f);
	std::cout << "Is the point inside the triangle? "
		<< (bsp(a, b, c, inside) ? "Yes" : "No") << std::endl;

	// Test point on the edge
	Point onEdge(2.5f, 0.0f);
	std::cout << "Is the point inside the triangle? "
		<< (bsp(a, b, c, onEdge) ? "Yes" : "No") << std::endl;

	// Test point outside the triangle
	Point outside(15.0f, 15.0f);
	std::cout << "Is the point inside the triangle? "
		<< (bsp(a, b, c, outside) ? "Yes" : "No") << std::endl;

	// Test point as a vertex
	Point vertex(0.0f, 0.0f);
	std::cout << "Is the point inside the triangle? "
		<< (bsp(a, b, c, vertex) ? "Yes" : "No") << std::endl;

	return 0;
}

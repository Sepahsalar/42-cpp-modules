/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:26:08 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/04 22:56:55 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cerr << "Error: The number of zombies must be greater than zero." << std::endl;
		return nullptr;
	}
	try
	{
		Zombie	*horde = new Zombie[N];
		for (int i = 0; i < N; i++)
			horde[i].setName(name);
		return horde;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return nullptr;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:41 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/04 22:36:19 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <exception>

class Zombie
{
	public:
		Zombie(std::string n);
		~Zombie();
		void	announce(void);

	private:
		std::string name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif

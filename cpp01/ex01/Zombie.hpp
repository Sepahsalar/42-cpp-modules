/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:41 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/04 22:58:24 by asohrabi         ###   ########.fr       */
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
		Zombie();
		~Zombie();
		void	announce(void);
		void	setName(std::string name);

	private:
		std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif

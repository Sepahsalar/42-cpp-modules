/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:29:19 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 16:05:02 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
	public:
		HumanB(const std::string &n);
		~HumanB();

		void		setWeapon(Weapon& weapon);
		void		attack() const;

	private:
		std::string	name;
		Weapon		*weapon;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:29:27 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 19:46:49 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Character.hpp
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string const &name);
		Character(Character const &src);
		Character			&operator=(Character const &rhs);
		~Character();

		std::string const	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);

	private:
		std::string			_name;
		AMateria			*_inventory[4];
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:13 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 15:39:25 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal &other);
		Animal			&operator=(const Animal &other);
		virtual			~Animal();

		virtual void	makeSound() const;
		std::string		getType() const;
	
	protected:
		std::string		type;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:13 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/10 15:39:25 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &other);
		AAnimal			&operator=(const AAnimal &other);
		virtual			~AAnimal();

		virtual void	makeSound() const = 0;
		std::string		getType() const;
	
	protected:
		std::string		type;
};

#endif

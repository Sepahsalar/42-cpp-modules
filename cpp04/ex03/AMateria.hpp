/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:27:29 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria(std::string const &type);
		AMateria(AMateria const &src);
		AMateria			&operator=(AMateria const &rhs);
		virtual				~AMateria();

		std::string const	&getType() const;

		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);

	protected:
		std::string _type;
};

#endif

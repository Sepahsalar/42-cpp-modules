/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:30:04 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/19 14:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource	&operator=(MateriaSource const &other);
		~MateriaSource();

		void			learnMateria(AMateria *m);
		AMateria		*createMateria(std::string const &type);

	private:
		AMateria		*_templates[4];
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:03:52 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/05 00:09:16 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Replacer
{
	public:
		Replacer(const std::string &filename
			, const std::string &s1, const std::string &s2);
		~Replacer();
		void	replaceAndSave(void) const;

	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
		void		_handleError(const std::string &message) const;
		std::string	_replaceOccurrences(const std::string &content) const;
};

#endif

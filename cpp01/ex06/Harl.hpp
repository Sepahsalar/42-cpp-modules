/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:34:58 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 16:38:40 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();

		void	filter(std::string level);

	private:
		void	_debug();
		void	_info();
		void	_warning();
		void	_error();
};

#endif

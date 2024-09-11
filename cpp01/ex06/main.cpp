/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@studenet.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 17:12:01 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:14:51 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <log level>" << std::endl;
		return 1;
	}

	Harl		harl;
	std::string	level(argv[1]);

	harl.filter(level);

	return 0;
}

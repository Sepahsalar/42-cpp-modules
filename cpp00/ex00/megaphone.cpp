/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:51:41 by asohrabi          #+#    #+#             */
/*   Updated: 2024/09/11 17:18:39 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int 		i;
	size_t 		j;
	std::string	str;
	
	i = 1;
	j = 0;
	if (argc != 1)
	{
		for (i = 1; i < argc; i++)
		{
			str = argv[i];
			for (j = 0; j < str.length(); j++)
				std::cout << (char)toupper(str[j]);
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}

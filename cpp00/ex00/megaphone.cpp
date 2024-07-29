/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asohrabi <asohrabi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:51:41 by asohrabi          #+#    #+#             */
/*   Updated: 2024/07/29 12:53:37 by asohrabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int i;
	int j;
	
	if (argc != 1)
	{
		for (i = 1; i < argc; i++)
			for (j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}

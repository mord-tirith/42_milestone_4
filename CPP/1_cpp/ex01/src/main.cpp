/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:34:00 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 21:46:15 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>

static int	getNumberInput(void) {
	int			value;
	char		trash;
	std::string	input;

	while (42)
	{
		std::cout << "Choose how many zombies to create:" << std::endl;
		if (!std::getline(std::cin, input))
			return (-1);
		if (input.empty())
			continue ;
		std::stringstream stream(input);
		if (!(stream >> value) || stream >> trash || value <= 0)
		{
			std::cout << "Number must be positive INT bigger than 0!" <<std::endl;
			continue ;
		}
		break ;
	}
	return (value);
}

int	main(int ac, char **av) {
	int			n;
	bool		debugMode;
	Zombie		*horde;
	std::string	input;

	debugMode = false;
	if (ac == 2)
	{
		input = av[1];
		if (input == "debug")
			debugMode = true;
	}

	while (42)
	{
		std::cout << "MAKE a horde or get out of here (EXIT):" << std::endl;

		if (!std::getline(std::cin, input))
			break ;
		if (input.empty())
			continue ;
		else if (input == "EXIT")
			break ;
		else if (input == "MAKE")
		{
			n = getNumberInput();
			if (n == -1)
				break ;
			while (42)
			{
				std::cout << "Name the horde zombies:" << std::endl;
				if (!std::getline(std::cin, input))
				{
					n = -1;
					break ;
				}
				if (input.empty())
					continue ;
				else
				{
					if (debugMode)
						horde = debugHorde(n, input);
					else
						horde = zombieHorde(n, input);
					break ;
				}
			}
			if (n == -1)
				break ;

			std::cout << "\nThe horde will now announce itself:" << std::endl;
			for (int i = 0; i < n; i++)
				horde[i].announce();
			
			std::cout << "\nAnd now they die:" << std::endl;
			delete[] horde;
		}
		else
			std::cout << "Unknown command: " << input << std::endl;
	}

	return (0);
}

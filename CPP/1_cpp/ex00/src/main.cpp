/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:46:08 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 19:22:11 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int	main(void)
{
	std::string	name;
	std::string	command;

	while (42)
	{

		std::cout << "Choose to add a ZOMBIE or a CHUMP (or just EXIT): " << std::endl;
		if (!std::getline(std::cin, command))
			break ;

		if (command.empty())
			continue ;

		if (command == "EXIT")
			break ;
		else if (command == "ZOMBIE")
		{
			std::cout << "Name the addZombie creature: " << std::endl;
			if (!std::getline(std::cin, name))
				break ;
			Zombie *z;
			z = newZombie(name);
			std::cout << "You have created the zombie " << name << "!" << std::endl;

			while (42)
			{
				std::cout << "Choose to ANNounce or to KILL your zombie: " << std::endl;
				if (!std::getline(std::cin, command))
				{
					delete z;
					break ;
				}
				if (command == "ANN")
					z->announce();
				else if (command == "KILL")
				{
					std::cout << "Zombie " << name << " is about to be deleted" << std::endl;
					delete z;
					break ;
				}
				else
					continue ;
			}
		}
		else if (command == "CHUMP")
		{
			std::cout << "Name the chump: " << std::endl;

			if (!std::getline(std::cin, name))
				break ;

			std::cout << "The chump " << name << " will be created, announce itself and then die now." << std::endl;

			randomChump(name);
		}
		else
			std::cout << "Unknown command: " << command << "." << std::endl;
	}

	return (0);
}

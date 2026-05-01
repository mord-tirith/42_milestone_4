/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:46:08 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 15:14:50 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	int		chumps = ac - 3;
	bool	secondBite = ac >= 3;
	Zombie*	patientTwo;

	if (ac <= 1)
	{
		std::cout << "You must name at least the Patient Zero!" << std::endl;
		return (1);
	}

	std::cout << "We'll first create a zombie with the class' constructor." << std::endl;
	
	Zombie patientZero(av[1]);

	std::cout << "Patient Zero (" << av[1] << ") will announce themselves:\n" << std::endl;
	patientZero.announce();

	if (ac >= 3)
	{
		std::cout << "\nWe'll now have " << av[1] << " bite someone named " << av[2] << " with the newZombie function:\n" << std::endl;
		patientTwo = patientZero.newZombie(av[2]);
		std::cout << "Patient Two (" << av[2] << ") will annount themselves:\n" << std::endl;
		patientTwo->announce();
	}

	for (int i = 0; i < chumps; i++)
	{
		if (i % 2)
		{
			std::cout << "\n" << av[1] << " has bitten someone else! Creating with randomChump:" << std::endl;
			patientZero.randomChump(av[i + 3]);
		}
		else
		{
			std::cout << "\n" << av[2] << " has gone and bitten another randomChump:" << std::endl;
			patientTwo->randomChump(av[i + 3]);
		}
	}
	
	if (ac >= 2)
		std::cout << std::endl;

	if (secondBite)
	{
		std::cout << "Poor " << av[2] << " is about to be deleted:" << std::endl;
		delete patientTwo;
	}

	std::cout << "\nAs the program ends, Patient Zero's destructor will be called automatically:" <<std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:34:00 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 15:43:06 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main() {
	Zombie patientZero("Allan");
	
	patientZero.announce();

	std::cout << "Allan will bite 7 random guys named Jake:\n" << std::endl;

	Zombie* myHorde = zombieHorde(7, "Jake");

	for (int i = 0; i < 7; i++)
		myHorde[i].announce();

	delete[] myHorde;
	return (0);
}

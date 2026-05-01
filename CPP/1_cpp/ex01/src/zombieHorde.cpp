/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 15:27:28 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 21:29:19 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie*	debugHorde(int N, std::string name) {
	Zombie*				horde;

	horde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		std::stringstream	newName;
		newName << name << " " << i;
		horde[i].setName(newName.str());
	}
	return (horde);
}

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	horde;

	horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);

	return (horde);
}

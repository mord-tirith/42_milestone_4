/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:55:50 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 23:03:07 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

int main() {
	{
		std::cout << "BOB'S TURN:" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		std::cout << std::endl;
	}
	{
		std::cout << "JIM'S TURN:" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		std::cout << std::endl;
	}
	{
		std::cout << "MARK'S TURN" << std::endl;
		Weapon sword("elegant and deadly long blade");
		HumanB mark("Mark");
		mark.attack();
		std::cout << "Mark found a sword!" << std::endl;
		mark.setWeapon(sword);
		mark.attack();
	}
	return 0;
}


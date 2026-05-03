/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:14:05 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 17:31:22 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

static bool	takeAction(ClapTrap& actor, ClapTrap& receiver) {
	std::string	command;
	std::string	name = actor.getName();
	std::string	target = receiver.getName();
	bool		canAttack;

	while (1) {
		std::cout << "What should " << name << " do? [1.ATTACK | 2.REPAIR]" << std::endl;

		if (!std::getline(std::cin, command))
			return false;
		else if (command.empty())
			continue ;

		if (command == "ATTACK" || command == "1.ATTACK" || command == "1" || command == "1.")
		{
			canAttack = actor.getEnergyPoints() > 0 && actor.getHitPoints() > 0;
			actor.attack(target);
			if (canAttack)
				receiver.takeDamage(actor.getAttackDamage());
			break ;
		}
		else if (command == "REPAIR" || command == "2.REPAIR" || command == "2" || command == "2.")
		{
			actor.beRepaired(1);
			break ;
		}
		else
			std::cout << name << " has no idea what '" << command << "' is supposed to mean." << std::endl;
	}
	std::cout << std::endl;
	return true;
}

int	main(void) {
	std::string	cmd;

	std::cout << "Welcome to ClapTrap battlemania 2000!" << std::endl;

	std::cout << "Today's fight is not fair at all, we have, Biiiiiiill the ScavTrap!" << std::endl;
	ScavTrap	bill("Bill");

	std::cout << "And squaring up against him with literally no chance in hell, is Mike the ClapTrap!" << std::endl;
	ClapTrap	mike("Mike");


	while (1)
	{
		std::cout << "EXIT or choose who will act! [1.BILL | 2.MIKE]" << std::endl;

		if (!std::getline(std::cin, cmd))
			break ;
		else if (cmd.empty())
			continue ;
		else if (cmd == "EXIT")
			break ;

		if (cmd == "1" || cmd == "1." || cmd == "BILL" || cmd == "1.BILL") {
			std::cout << std::endl;
			if (!takeAction(bill, mike))
				break ;
			else
				continue ;
		}
		else if (cmd == "2" || cmd == "2." || cmd == "MIKE" || cmd == "2.MIKE") {
			std::cout << std::endl;
			if (!takeAction(mike, bill))
				break ;
			else
				continue ;
		}
		else
			std::cout << "No no no, " << cmd << "wasn't an option!" << std::endl;
	}

	return 0;
}

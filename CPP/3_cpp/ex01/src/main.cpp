/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:14:05 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 15:42:54 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

static bool	takeAction(ScavTrap& actor, ScavTrap& receiver) {
	std::string	command;
	std::string	name = actor.getName();
	std::string	target = receiver.getName();

	while (1) {
		std::cout << "What should " << name << " do? [1.ATTACK | 2.REPAIR]" << std::endl;

		if (!std::getline(std::cin, command))
			return false;
		else if (command.empty())
			continue ;

		if (command == "ATTACK" || command == "1.ATTACK" || command == "1" || command == "1.")
		{
			actor.attack(target);
			if (actor.getEnergyPoints() > 0 && actor.getHitPoints() > 0)
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

	ScavTrap	adam("Adam");
	ScavTrap	beth("Betthany");

	while (1)
	{
		std::cout << "EXIT or choose who will act! 1. ADAM | 2. BETH" << std::endl;

		if (!std::getline(std::cin, cmd))
			break ;
		else if (cmd.empty())
			continue ;
		else if (cmd == "EXIT")
			break ;

		if (cmd == "1" || cmd == "1." || cmd == "ADAM") {
			std::cout << std::endl;
			if (!takeAction(adam, beth))
				break ;
			else
				continue ;
		}
		else if (cmd == "2" || cmd == "2." || cmd == "BETH") {
			std::cout << std::endl;
			if (!takeAction(beth, adam))
				break ;
			else
				continue ;
		}
		else
			std::cout << "No no no, " << cmd << "wasn't an option!" << std::endl;
	}

	return 0;
}

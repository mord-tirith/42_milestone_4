/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 13:14:05 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/04 16:17:18 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

static int	translateAction(const std::string& command) {
	if (command == "ATTACK" || command == "1.ATTACK"
			|| command == "1" || command == "1.")
		return 1;
	if (command == "REPAIR" || command == "2.REPAIR"
			|| command == "2" || command == "2.")
		return 2;
	if (command == "SPECIAL" || command == "3.SPECIAL"
			|| command == "3" || command == "3.")
		return 3;
	return -1;
}

static bool	takeAction(ClapTrap& actor, ClapTrap& receiver) {
	int			action;
	bool		canAttack;
	std::string	command;
	std::string	name = actor.getName();
	std::string	target = receiver.getName();

	while (1) {
		std::cout << "What should " << name << " do? [1.ATTACK | 2.REPAIR | 3.SPECIAL]" << std::endl;

		if (!std::getline(std::cin, command))
			return false;
		else if (command.empty())
			continue ;
		action = translateAction(command);
		if (action == 1)
		{
			canAttack = actor.getEnergyPoints() > 0 && actor.getHitPoints() > 0;
			actor.attack(target);
			if (canAttack)
				receiver.takeDamage(actor.getAttackDamage());
			break ;
		}
		else if (action == 2)
		{
			actor.beRepaired(1);
			break ;
		}
		else if (action == 3)
		{
			actor.special();
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

	std::cout << "We have a fair match for once today, our winner from the last match: Bill the ScavTrap!" << std::endl;
	ScavTrap	bill("Bill");

	std::cout << "Going up against a real challenge this time: Louise, the FragTrap!" << std::endl;
	FragTrap	louise("Louise");


	while (1)
	{
		std::cout << "EXIT or choose who will act! [1.BILL | 2.LOUISE]" << std::endl;

		if (!std::getline(std::cin, cmd))
			break ;
		else if (cmd.empty())
			continue ;
		else if (cmd == "EXIT")
			break ;

		if (cmd == "1" || cmd == "1." || cmd == "BILL" || cmd == "1.BILL") {
			std::cout << std::endl;
			if (!takeAction(bill, louise))
				break ;
			else
				continue ;
		}
		else if (cmd == "2" || cmd == "2." || cmd == "LOUISE" || cmd == "2.LOUISE") {
			std::cout << std::endl;
			if (!takeAction(louise, bill))
				break ;
			else
				continue ;
		}
		else
			std::cout << "No no no, " << cmd << "wasn't an option!" << std::endl;
	}

	return 0;
}

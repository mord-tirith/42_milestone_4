/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:47:32 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 22:52:56 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon &equipment) {
	_name = name;
	_weapon = &equipment;
}

HumanB::~HumanB(void) {
}

void	HumanB::attack(void) const {
	if (_weapon == NULL)
		std::cout << "Poor " << _name << " can't attack without weapons!"<< std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
} 

void	HumanB::setWeapon(Weapon& equipment) {
	_weapon = &equipment;
}

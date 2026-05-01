/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:41:34 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 22:47:13 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &equipment) {
	_name = name;
	_weapon = &equipment;
}

HumanA::~HumanA(void) {
}

void	HumanA::attack(void) const {
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

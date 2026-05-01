/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:53:12 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 22:55:36 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	_type = type;
}

void	Weapon::setType(std::string newType) {
	_type = newType;
}

std::string Weapon::getType(void) const {
	return (_type);
}

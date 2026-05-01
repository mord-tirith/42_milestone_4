/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:35:07 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 22:49:23 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon& equipment);
		~HumanB(void);
		void	attack(void) const;
		void	setWeapon(Weapon& equipment);

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif

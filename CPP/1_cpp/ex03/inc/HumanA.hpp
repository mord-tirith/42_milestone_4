/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:35:07 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 22:44:19 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string name, Weapon &equipment);
		~HumanA(void);
		void	attack(void) const;

	private:
		std::string	_name;
		Weapon*		_weapon;
};

#endif

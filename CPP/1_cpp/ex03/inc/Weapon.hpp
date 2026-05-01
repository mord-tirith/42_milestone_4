/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:31:55 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 22:53:49 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	public:
		Weapon(std::string type);
		void		setType(std::string newType);
		std::string	getType(void) const;

	private:
		std::string	_type;
};

#endif

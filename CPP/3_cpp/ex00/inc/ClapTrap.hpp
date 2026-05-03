/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:46:21 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 13:41:55 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
	public:
		ClapTrap(void);
		ClapTrap(const std::string& name);
		ClapTrap(const ClapTrap& that);
		~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap& that);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		int			getAttackDamage(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		std::string	getName(void) const;

	private:
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;
		std::string	name;
};

#endif

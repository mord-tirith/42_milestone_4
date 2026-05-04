/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:46:21 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/04 16:13:28 by thenriqu         ###   ########.fr       */
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
		virtual ~ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap& that);

		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
		virtual void	special(void);

		int			getHitPoints(void) const;
		int			getAttackDamage(void) const;
		int			getEnergyPoints(void) const;

		void	setHitPoints(int newHitPoints);
		void	setEnergyPoints(int newEnergyPoints);
		void	setAttackDamage(int newAttackDamage);

		std::string	getName(void) const;

	private:
		int			hitPoints;
		int			energyPoints;
		int			attackDamage;
		std::string	name;
};

#endif

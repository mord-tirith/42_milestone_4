/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 14:57:40 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/04 16:35:59 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& that);
		~FragTrap(void);

		FragTrap&	operator=(const FragTrap& that);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	special(void);

		void	highFivesGuys(void);

	private:
		int		highFiveTurns;
		bool	hasHighFive;
		void	tickHighFive(void);

	protected:
		static const int	HP = 100;
		static const int	EP = 100;
		static const int	AD = 30;
		static const int	HF = 3;
};

#endif

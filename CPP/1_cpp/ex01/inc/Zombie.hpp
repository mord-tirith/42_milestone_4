/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:25:26 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 21:41:04 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie(void);
		Zombie(const std::string& name);
		~Zombie(void);
		void	announce(void) const;
		void	setName(std::string name);

	private:
		std::string	_name;
};

Zombie*	debugHorde(int N, std::string name);
Zombie*	zombieHorde(int N, std::string name);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 13:25:26 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 14:40:08 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define	ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie(const std::string& name);
		~Zombie(void);
		void	announce(void) const;
		void	randomChump(std::string name);
		Zombie*	newZombie(std::string name);

	private:
		std::string	_name;
};

#endif

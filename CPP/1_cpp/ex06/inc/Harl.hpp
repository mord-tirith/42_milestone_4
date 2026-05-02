/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:33:58 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 12:44:19 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

typedef enum e_levels {
	DEBUG,
	INFO,
	WARN,
	ERROR,
	UNKNOWN
}	t_levels;

int	translateLevel(std::string level);

class	Harl {
	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level) const;
		void	levelComplain(std::string level) const;

	private:
		void	debug(void) const;
		void	info(void)	const;
		void	warning(void) const;
		void	error(void) const;
};

#endif

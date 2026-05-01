/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:33:58 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 23:38:38 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class	Harl {
	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level) const;

	private:
		void	debug(void) const;
		void	info(void)	const;
		void	warning(void) const;
		void	error(void) const;
};

#endif

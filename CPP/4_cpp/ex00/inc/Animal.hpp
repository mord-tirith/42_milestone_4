/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:11:35 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 12:28:50 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

#define C_RED		"\033[31m"
#define C_GREEN		"\033[32m"
#define	C_YELLOW	"\033[33m"
#define	C_PURPLE	"\033[34m"
#define	C_PINK		"\033[35m"
#define	C_BLUE		"\033[36m"
#define	C_WHITE		"\033[0m"

class	Animal {
	public:
		Animal(void);
		Animal(const std::string& type);
		Animal(const Animal& that);
		virtual ~Animal(void);

		Animal&	operator=(const Animal& that);

		std::string	getType(void) const;

		virtual void	makeSound(void) const;
		virtual Animal*	clone(void) const;
	
	protected:
		std::string	type;
};

#endif

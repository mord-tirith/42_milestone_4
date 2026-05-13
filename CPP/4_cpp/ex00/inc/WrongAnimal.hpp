/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:21:57 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 14:21:59 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

#define C_RED		"\033[31m"
#define C_GREEN		"\033[32m"
#define	C_YELLOW	"\033[33m"
#define	C_PURPLE	"\033[34m"
#define	C_PINK		"\033[35m"
#define	C_BLUE		"\033[36m"
#define	C_WHITE		"\033[0m"

class	WrongAnimal {
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& that);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(const WrongAnimal& that);

		std::string	getType(void) const;

		virtual void	makeSound(void) const;
		virtual WrongAnimal*	clone(void) const;
	
	protected:
		std::string	type;
};

std::string	rotType(const std::string& type);

#endif

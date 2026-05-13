/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:27:32 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 12:07:50 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DOG_HPP
#define	DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
	public:
		Dog(void);
		Dog(const std::string& type);
		Dog(const Dog& that);
		~Dog(void);

		Dog&	operator=(const Dog& that);

		void	makeSound(void) const;
		Animal*	clone(void) const;

	private:
		void	printer(const std::string& message) const;
};

#endif

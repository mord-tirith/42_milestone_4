/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:27:32 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 12:08:03 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CAT_HPP
#define	CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
	public:
		Cat(void);
		Cat(const std::string& type);
		Cat(const Cat& that);
		~Cat(void);

		Cat&	operator=(const Cat& that);

		void	makeSound(void) const;
		Animal*	clone(void) const;

	private:
		void	printer(const std::string& message) const;
};

#endif

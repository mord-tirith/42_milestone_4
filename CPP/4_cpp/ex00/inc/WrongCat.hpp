/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:04:45 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 14:12:31 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WRONGCAT_HPP
#define	WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const std::string& type);
		WrongCat(const WrongCat& that);
		~WrongCat(void);

		WrongCat&	operator=(const WrongCat& that);

		void	makeSound(void) const;
		WrongAnimal*	clone(void) const;

	private:
		void	printer(const std::string& message) const;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:35:11 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 20:40:04 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define	FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed& that);
		Fixed(const int newValue);
		Fixed(const float newValue);
		~Fixed(void);

		Fixed & operator=(const Fixed& that);

		int		getRawBits(void) const;
		int		toInt(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;

	private:
		int					_value;
		const static int	_digits = 8;
};

std::ostream & operator<<(std::ostream& stream, const Fixed& thisObject);

#endif

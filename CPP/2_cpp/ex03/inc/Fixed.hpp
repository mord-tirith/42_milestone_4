/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:35:11 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 21:04:46 by mord             ###   ########.fr       */
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

		Fixed&	operator=(const Fixed& that);
		Fixed	operator+(const Fixed& that) const;
		Fixed	operator-(const Fixed& that) const;
		Fixed	operator*(const Fixed& that) const;
		Fixed	operator/(const Fixed& that) const;
		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		bool	operator>(const Fixed& that) const;
		bool	operator>=(const Fixed& that) const;
		bool	operator<(const Fixed& that) const;
		bool	operator<=(const Fixed& that) const;
		bool	operator==(const Fixed& that) const;
		bool	operator!=(const Fixed& that) const;

		int		getRawBits(void) const;
		int		toInt(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;

		static Fixed&		min(Fixed& value1, Fixed& value2);
		static Fixed&		max(Fixed& value1, Fixed& value2);
		static const Fixed&	min(const Fixed& value1, const Fixed& value2);
		static const Fixed&	max(const Fixed& value1, const Fixed& value2);


	private:
		int					_value;
		const static int	_digits = 8;
};

std::ostream & operator<<(std::ostream& stream, const Fixed& thisObject);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:35:11 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 19:49:18 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define	FIXED_HPP

class Fixed {
	public:
		Fixed(void);
		Fixed(const Fixed& that);
		~Fixed(void);
		Fixed & operator=(const Fixed& that);

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

	private:
		int					_value;
		const static int	_digits = 8;
};

#endif

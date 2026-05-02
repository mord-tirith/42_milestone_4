/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:14:15 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 23:54:06 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <ostream>

class Point {
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point& that);
		~Point(void);

		Point&	operator=(const Point& that);
		Point	operator-(const Point& that) const;

		float	getX(void) const;
		float	getY(void) const;

	private:
		const Fixed	x;
		const Fixed	y;
};

float			crossProduct(const Point& one, const Point& two, const Point& three);
std::ostream&	operator<<(std::ostream& stream, const Point& thisObject);

#endif

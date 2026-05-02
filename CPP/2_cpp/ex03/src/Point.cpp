/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 23:25:51 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/03 00:24:53 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <ostream>

/*  Constructors and Destructors  */
Point::Point(void): x(0), y(0) {};

Point::Point(const float x, const float y): x(x), y(y) {};

Point::Point(const Point& that): x(that.x), y(that.y) {};

Point::~Point(void) {};

/*  Operator Overloads  */

Point&	Point::operator=(const Point& that) {
	(void) that;
	return *this;
}

Point Point::operator-(const Point& that) const {
	return Point((this->getX() - that.getX()), (this->getY() - that.getY()));
}

std::ostream&	operator<<(std::ostream& stream, const Point& thisObject) {
	stream << "[" << thisObject.getX() << ":" << thisObject.getY() << "]";
	return stream;
}

/*  Getters  */

float	Point::getX(void) const {
	return x.toFloat();
}
float	Point::getY(void) const {
	return y.toFloat();
}

/* Special Stuff */

float	crossProduct(const Point& a, const Point& b, const Point& p) {
	Point	evens = b - a;
	Point	odds = p - a;
	return evens.getX() * odds.getY() - evens.getY() * odds.getX();
}

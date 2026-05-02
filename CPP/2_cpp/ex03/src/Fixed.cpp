/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:38:13 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 22:21:19 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

/* Constructors and Destructors: */

Fixed::Fixed(void) {
	this->_value = 0;
}

Fixed::Fixed(const Fixed& that) {
	*this = that;
}

Fixed::Fixed(const int newValue) {
	this->_value = newValue << this->_digits;
}

Fixed::Fixed(const float newValue) {
	this->_value = (int)roundf(newValue * (1 << this->_digits));
}

Fixed::~Fixed(void) {
}

/*  Operators Overloads:  */
//	Fixed family:
Fixed &Fixed::operator=(const Fixed& that) {
	this->_value = that.getRawBits();
	return (*this);
}

Fixed Fixed::operator+(const Fixed& that) const {
	Fixed	res;
	res.setRawBits(this->_value + that._value);
	return res;
}

Fixed Fixed::operator-(const Fixed& that) const {
	Fixed res;
	res.setRawBits(this->_value + that._value);
	return res;
}

Fixed Fixed::operator*(const Fixed& that) const {
	return Fixed(this->toFloat() * that.toFloat());
}

Fixed Fixed::operator/(const Fixed& that) const {
	return Fixed(this->toFloat() / that.toFloat());
}

Fixed Fixed::operator++(void) {
	++(this->_value);
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed	temp(*this);

	++(this->_value);
	return (temp);
}

Fixed Fixed::operator--(void) {
	--(this->_value);
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	temp(*this);

	--(this->_value);
	return (temp);
}

//	Ostream family:
std::ostream & operator<<(std::ostream& stream, const Fixed& thisObject) {
	stream << thisObject.toFloat();
	return (stream);
}

//	Bool family:
bool	Fixed::operator>(const Fixed& that) const {
	return this->_value > that._value;
}

bool	Fixed::operator>=(const Fixed& that) const {
	return this->_value >= that._value;
}

bool	Fixed::operator<(const Fixed& that) const {
	return this->_value < that._value;
}

bool	Fixed::operator<=(const Fixed& that) const {
	return this->_value <= that._value;
}

bool	Fixed::operator==(const Fixed& that) const {
	return this->_value == that._value;
}

bool	Fixed::operator!=(const Fixed& that) const {
	return this->_value != that._value;
}

/*  Getters and Setters  */

int	Fixed::getRawBits(void) const {
	return (_value);
}

void	Fixed::setRawBits(const int raw) {
	_value = raw;
}

/*  Casters  */

int	Fixed::toInt(void) const {
	return this->_value >> this->_digits;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_value / (1 << this->_digits));
}

/*  MinMax  */

Fixed&	Fixed::min(Fixed& value1, Fixed& value2) {
	return value1 < value2 ? value1 : value2;
}

Fixed&	Fixed::max(Fixed& value1, Fixed& value2) {
	return value1 > value2 ? value1 : value2;
}

const Fixed&	Fixed::min(const Fixed& value1, const Fixed& value2) {
	return value1 < value2 ? value1 : value2;
}

const Fixed&	Fixed::max(const Fixed& value1, const Fixed& value2) {
	return value1 > value2 ? value1 : value2;
}

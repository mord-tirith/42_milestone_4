/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:38:13 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 20:53:19 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed& that) {
	std::cout << "Copy constructor called" << std::endl;
	*this = that;
}

Fixed::Fixed(const int newValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = newValue << this->_digits;
}

Fixed::Fixed(const float newValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = (int)roundf(newValue * (1 << this->_digits));
}

Fixed &Fixed::operator=(const Fixed& that) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = that.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream& stream, const Fixed& thisObject) {
	stream << thisObject.toFloat();
	return (stream);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return (_value);
}

int	Fixed::toInt(void) const {
	return this->_value >> this->_digits;
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_value / (1 << this->_digits));
}


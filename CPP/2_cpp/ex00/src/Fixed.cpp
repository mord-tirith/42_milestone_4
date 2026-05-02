/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 19:38:13 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 19:50:35 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const Fixed& that) {
	std::cout << "Copy constructor called" << std::endl;
	*this = that;
}

Fixed &Fixed::operator=(const Fixed& that) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = that.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

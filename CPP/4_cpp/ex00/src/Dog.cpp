/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:19:16 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/08 12:02:07 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

/*  Constructors and Destructors  */

Dog::Dog(void) {
	std::cout << C_YELLOW << "[Dog] Dog(void) Constructor called" << C_WHITE << "\n";
	type = "Generic Dog";
}

Dog::Dog(const std::string& type) {
	std::cout << C_YELLOW << "[Dog] Dog(" << type << ") Constructor called" << C_WHITE << "\n";
	this->type = type + " " + "Dog";
}

Dog::Dog(const Dog& that) {
	std::cout << C_YELLOW << "[Dog] Dog(" << that.type << ") Constructor called" << C_WHITE << "\n";
	*this = that;
}

Dog::~Dog(void) {
	std::cout << C_YELLOW << "[Dog] ~Dog(" << type << ") Destructor called" << C_WHITE << "\n";
}

/*  Operator Overloads  */

Dog&	Dog::operator=(const Dog& that) {
	std::cout << C_YELLOW << "[Dog] Operator '=' overload called: " << type << " = " << that.type << C_WHITE << "\n";
	this->type = that.type;
	return *this;
}

/*  Member Functions  */

// Mandatory
void	Dog::makeSound(void) const {
	std::cout << C_YELLOW << "[Dog](" << type << ") Bark!" << C_WHITE << "\n";
}





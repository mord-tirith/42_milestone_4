/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:19:16 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 12:29:37 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <string>

/*  Constructors and Destructors  */

Animal::Animal(void) {
	std::cout << C_WHITE << "[Animal] Animal(void) Constructor called" << "\n";
	type = "Generic";
}

Animal::Animal(const std::string& type) {
	std::cout << C_WHITE << "[Animal] Animal(" << type << ") Constructor called" << "\n";
	this->type = type + " " + "Animal";
}

Animal::Animal(const Animal& that) {
	std::cout << C_WHITE << "[Animal] Animal(" << that.type << ") Constructor called" << "\n";
	*this = that;
}

Animal::~Animal(void) {
	std::cout << C_WHITE << "[Animal] ~Animal(" << type << ") Destructor called" << "\n";
}

/*  Operator Overloads  */

Animal&	Animal::operator=(const Animal& that) {
	std::cout << C_WHITE << "[Animal] Operator '=' overload called: " << this->type << " = " << that.type << "\n";
	this->type = that.type;
	return *this;
}

/*  Getters and Setters  */

std::string	Animal::getType(void) const {
	return this->type;
}

/*  Member Functions  */

// Mandatory
void	Animal::makeSound(void) const {
	std::cout << C_WHITE << "[Animal](" << type << "): I have no type and I must... Scream?" << "\n";
}

// My Own Stuff
Animal*	Animal::clone(void) const {
	return new Animal(*this);
}



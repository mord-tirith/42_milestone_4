/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:19:16 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/08 12:08:45 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

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

/*  Member Functions  */

// Mandatory
void	Animal::makeSound(void) const {
	std::cout << C_WHITE << "[Animal](" << type << "): I have no type and I must... Scream?" << "\n";
}





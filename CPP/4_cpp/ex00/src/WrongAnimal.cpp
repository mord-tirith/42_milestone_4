/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:21:34 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 14:27:58 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

/*  Constructors and Destructors  */

WrongAnimal::WrongAnimal(void) {
	std::cout << C_WHITE << "[WrongAnimal] WrongAnimal(void) Constructor called. This feels off..." << "\n";
	type = "Creepy";
}

WrongAnimal::WrongAnimal(const std::string& type) {
	std::cout << C_WHITE << "[WrongAnimal] WrongAnimal(" << type << ") Constructor called, but did it work?" << "\n";
	this->type = rotType(type) + " " + "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& that) {
	std::cout << C_WHITE << "[WrongAnimal] WrongAnimal(" << that.type << ") Constructor called..." << "\n";
	*this = that;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << C_WHITE << "[WrongAnimal] ~WrongAnimal(" << type << ") Destructor called" << "\n";
}

/*  Operator Overloads  */

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& that) {
	std::cout << C_WHITE << "[WrongAnimal] Operator '=' overload called: " << this->type << " = " << that.type << ". At least, in theory.\n";
	this->type = rotType(that.type);
	return *this;
}

/*  Getters and Setters  */

std::string	WrongAnimal::getType(void) const {
	return this->type;
}

/*  Member Functions  */

// Mandatory
void	WrongAnimal::makeSound(void) const {
	std::cout << C_WHITE << "[WrongAnimal](" << type << "): Some ungodly screetch." << "\n";
}

// My Own Stuff
WrongAnimal*	WrongAnimal::clone(void) const {
	return new WrongAnimal(*this);
}


std::string	rotType(const std::string& type) {
	std::string	transform = type;

	for (std::basic_string<char>::size_type i = 0; i < type.length(); i++)
		transform[i] = type[i] % 2 ? type[i] - 15 : type[i] + 15;

	return transform;
}


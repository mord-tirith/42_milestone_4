/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:21:38 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 14:21:41 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include <iostream>

/*  Constructors and Destructors  */

WrongCat::WrongCat(void) {
	std::cout << C_BLUE << "[WrongCat] WrongCat(void) Constructor called. But this isn't a cat?" << C_WHITE << "\n";
	type = "Creepy";
}

WrongCat::WrongCat(const std::string& type) {
	std::cout << C_BLUE << "[WrongCat] WrongCat(" << type << ") Constructor called. Allegedly." << C_WHITE << "\n";
	this->type = rotType(type) + " " + "WrongCat";
}

WrongCat::WrongCat(const WrongCat& that) {
	std::cout << C_BLUE << "[WrongCat] WrongCat(" << that.type << ") Constructor called. It's spreading..." << C_WHITE << "\n";
	*this = that;
}

WrongCat::~WrongCat(void) {
	std::cout << C_BLUE << "[WrongCat] ~WrongCat(" << type << ") Destructor called. Finally." << C_WHITE << "\n";
}

/*  Operator Overloads  */

WrongCat&	WrongCat::operator=(const WrongCat& that) {
	std::cout << C_BLUE << "[WrongCat] Operator '=' overload called: " << type << " = " << that.type << ". Why would you do this?" << C_WHITE << "\n";
	this->type = that.type;
	return *this;
}

/*  Member Functions  */

// Mandatory
void	WrongCat::makeSound(void) const {
	std::cout << C_BLUE << "[WrongCat](" << type << "): Makes a creepy scratchy noise." << C_WHITE << "\n";
}

// My Own Stuff
WrongAnimal*	WrongCat::clone(void) const {
	return new WrongCat(*this);
}


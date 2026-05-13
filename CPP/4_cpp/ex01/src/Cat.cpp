/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 15:19:16 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 12:10:41 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

/*  Constructors and Destructors  */

Cat::Cat(void) {
	std::cout << C_BLUE << "[Cat] Cat(void) Constructor called" << C_WHITE << "\n";
	type = "Generic Cat";
}

Cat::Cat(const std::string& type) {
	std::cout << C_BLUE << "[Cat] Cat(" << type << ") Constructor called" << C_WHITE << "\n";
	this->type = type + " " + "Cat";
}

Cat::Cat(const Cat& that) {
	std::cout << C_BLUE << "[Cat] Cat(" << that.type << ") Constructor called" << C_WHITE << "\n";
	*this = that;
}

Cat::~Cat(void) {
	std::cout << C_BLUE << "[Cat] ~Cat(" << type << ") Destructor called" << C_WHITE << "\n";
}

/*  Operator Overloads  */

Cat&	Cat::operator=(const Cat& that) {
	std::cout << C_BLUE << "[Cat] Operator '=' overload called: " << type << " = " << that.type << C_WHITE << "\n";
	this->type = that.type;
	return *this;
}

/*  Member Functions  */

// Mandatory
void	Cat::makeSound(void) const {
	std::cout << C_BLUE << "[Cat](" << type << ") Meow?" << C_WHITE << "\n";
}

// My Own Stuff
Animal*	Cat::clone(void) const {
	return new Cat(*this);
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:12:48 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 15:19:56 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstddef>
#include <iostream>

/*  Constructors and Destructors  */

Brain::Brain(void) {
	std::cout << "Brain(void) constructor called\n";
	bootIdeas();
}

Brain::Brain(const std::string *ideas, size_t listSize) {
	std::cout << "Brain(std::string* ideas, size_t listSize) constructor called\n";
	bootIdeas();
	if (listSize < 0)
		std::cout << "Bad bad bad, don't use a negative sized array!\n";
	else {
		if (listSize > 100)
			listSize = 100;
		for (size_t i = 0; i < listSize; i++)
			this->ideas[i] = ideas[i].c_str();
	}
}

Brain::Brain(const Brain& that) {
	std::cout << "Brain(const Brain& that) constructor called\n";
	*this = that;
}

/*  Operator Overloads  */

Brain&	Brain::operator=(const Brain& that) {
	std::cout << "Brain Operator '=' overload called\n";
	for (size_t i = 0; i < MAX_IDEAS; i++)
		this->ideas[i] = that.ideas[i];
	return *this;
}

/*  Getters and Setters */

void	Brain::setIdea(const std::string& newIdea, size_t index) {
	if (index >= MAX_IDEAS || index < 0) {
		std::cout << "New Idea Index must be between 0 and " << MAX_IDEAS - 1 << "\n";
		return ;
	}
	this->ideas[index] = newIdea.c_str();
}

std::string	Brain::getIdea(size_t index) const {
	if (index >= MAX_IDEAS || index < 0) {
		std::cout << "Idea Index must be between 0 and " << MAX_IDEAS - 1 << "\n";
		return ("");
	}
	return this->ideas[index];
}

void	Brain::bootIdeas(void) {
	for (size_t i = 0; i < MAX_IDEAS; i++)
		this->ideas[i] = "### EMPTY IDEA SLOT ###";
}

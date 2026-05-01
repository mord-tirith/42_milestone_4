/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:37:48 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 00:06:21 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>
#include <iostream>

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void	Harl::debug(void) const {
	std::cout << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-pickle-speical-ketchup burger. Ireally do!" << std::endl;
}

void	Harl::info(void) const {
	std::cout << "[ INFO ] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) const {
	std::cout << "[ WARNING ] I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void) const {
	std::cout << "[ ERROR ] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) const {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[4])() const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return ;
		}
	}
	std::cout << "Harl doesn't understand this weird request:" << level << std::endl;
}

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
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-pickle-speical-ketchup burger. I really do!\n" << std::endl;
}

void	Harl::info(void) const {
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void) const {
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << std::endl;
}

void	Harl::error(void) const {
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
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

void	Harl::levelComplain(std::string level) const {
	int	filter = translateLevel(level);

	if (filter == UNKNOWN)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}

	switch (filter)
	{
		case DEBUG:
			complain("DEBUG"); complain("INFO"); complain("WARNING"); complain("ERROR");
			break ;
		case INFO:
			complain("INFO"); complain("WARNING"); complain("ERROR");
			break ;
		case WARN:
			complain ("WARNING"); complain("ERROR");
			break ;
		case ERROR:
			complain("ERROR");
			break ;
	}
}

int	translateLevel(std::string level) {
	if (level == "DEBUG")
		return DEBUG;
	else if (level == "INFO")
		return INFO;
	else if (level == "WARNING")
		return WARN;
	else if (level == "ERROR")
		return ERROR;
	else
		return UNKNOWN;
}

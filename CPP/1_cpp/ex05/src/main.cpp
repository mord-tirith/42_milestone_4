/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:59:06 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 00:03:43 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int	main(void) {
	Harl		myHarl;
	std::string	input;

	std::cout << "Welcome to Harl 2.0!" << std::endl;
	while (42) {
		std::cout << "Ask for HELP, hear a complaint or EXIT: " << std::endl;
		
		if (!std::getline(std::cin, input))
			break ;

		if (input.empty())
			continue ;

		if (input == "EXIT")
			break ;
		else if (input == "HELP")
		{
			std::cout << "You can use DEBUG, INFO, WARNING and ERROR to see messages from Harl." << std::endl;
			continue ;
		}
		else
			myHarl.complain(input);
	}
	return (0);
}

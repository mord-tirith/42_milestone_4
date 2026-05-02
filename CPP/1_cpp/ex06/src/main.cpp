/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 23:59:06 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/02 12:58:01 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>

int	main(int ac, char **av) {

	Harl		harl;
	std::string	level;

	if (ac != 2)
	{
		harl.levelComplain("err");
		return (1);
	}

	level = av[1];
	harl.levelComplain(level);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 22:16:36 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/01 22:30:01 by mord             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string		stringREAL = "HI THIS IS BRAIN";
	std::string*	stringPTR = &stringREAL;
	std::string&	stringREF = stringREAL;

	std::cout << "Address part:" << std::endl;
	std::cout << "Memory address of string variable: " << &stringREAL << std::endl;
	std::cout << "Memory address held by stringPTR:  " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:  " << &stringREF << std::endl;

	std::cout <<"\nValue part:" << std::endl;
	std::cout << "Value held by string variable:     " << stringREAL << std::endl;
	std::cout << "Value held by stringPTR:           " << *stringPTR << std::endl;
	std::cout << "Value held by stringREF:           " << stringREF << std::endl;

	return (0);
}

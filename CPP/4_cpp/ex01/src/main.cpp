/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:08:39 by thenriqu          #+#    #+#             */
/*   Updated: 2026/05/11 15:08:41 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"

void	runWrong(void) {

	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();
	delete i;
	delete meta;
}

void	runNormal(void) {

	const Animal* j = new Dog();
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete i;
	delete j;
	delete meta;
}


int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Running normal main:\n";
		runNormal();
		std::cout << "\nRunning Wrong main:\n";
		runWrong();
		return 0;
	}
	std::string command = av[1];
	if (command == "1" || command == "normal")
		runNormal();
	else if (command == "2" || command == "wrong")
		runWrong();
	else
		std::cout << "Usage: ./main [1.normal|2.wrong]" << std::endl;
	return 0;
}

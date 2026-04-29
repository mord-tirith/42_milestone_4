#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void) {
	PhoneBook	phonebook;
	std::string	command;

	while (42)
	{
		std::cout << "Enter command [ADD, SEARCH, EXIT]: ";

		if (!std::getline(std::cin, command))
			break ;

		if (command == "ADD")
			phonebook.add();
		else if (command == "SEARCH")
			phonebook.search();
		else if (command == "EXIT")
			break ;
		else
			std::cout << "Unknown command: " << command << "." << std::endl;
	}
	return (0);
}

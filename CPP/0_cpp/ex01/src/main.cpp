#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

int	main(void) {
	bool		searched;
	PhoneBook	phonebook;
	std::string	command;

	searched = false;
	while (42)
	{
		std::cout << "Enter command [ADD, SEARCH, EXIT]: ";

		if (!std::getline(std::cin, command))
			break ;

		if (command.empty())
			continue ;
		else if (command == "EXIT")
			break ;

		if (searched)
		{
			system("clear");
			searched = false;
		}

		if (command == "ADD")
		{
			phonebook.add();
			system("clear");
		}
		else if (command == "SEARCH")
		{
			phonebook.search();
			searched = true;
		}
		else
			std::cout << "Unknown command: " << command << "." << std::endl;
	}
	return (0);
}

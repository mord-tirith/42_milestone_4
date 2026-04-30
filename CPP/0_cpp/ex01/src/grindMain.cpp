#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>



int	main(void) {
	bool		searched;
	PhoneBook	phonebook;
	Contact		seeded_list[8];
	std::string	command;

	seeded_list[0] = Contact("Kaladin", "Stormblessed", "Kal", "4", 
			"Fears he won't be able to keep anyone he cares about safe", 1);

	seeded_list[1] = Contact("Shallan", "Davar", "Veil", "2", 
			"Too many too dark to list", 2);

	seeded_list[2] = Contact("Dalinar", "Kholin", "Blackthorn", "10",
			"Afraid he's a hypocrite", 3);

	seeded_list[3] = Contact("Janagawn", "Aqassix", "Gawks", "14",
			"Wants to stop being a figurehead leader", 4);

	seeded_list[4] = Contact("Khoravellium", "Avast", "Kor", "???",
			"Too passive to solve issues before they blow up", 5);

	seeded_list[5] = Contact("Vargo", "Taravangian", "King T", "9",
			"Not even trying to get started with this one", 6);

	seeded_list[6] = Contact("Numuhukumakiaki", "Aialunamor", "Rock", "3",
			"Devoutly pacifistic", 7);

	seeded_list[7] = Contact("Adolin", "Kholin", "Whitespine", "21",
			"Not sure whether to try to live up to his father's reputation or to ignore it", 8);

	for (int i = 0; i < 8; i++)
		phonebook.silentAdd(seeded_list[i]);

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

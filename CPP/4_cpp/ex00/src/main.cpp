
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>
#include <string>


int			which = 0;
const int	ARRAY_SIZE = 5;
bool		slots[ARRAY_SIZE] = {false};
Animal*		animals[ARRAY_SIZE];

typedef enum	e_prompts {
	BASIC,
	CAT,
	DOG,
}	t_prompts;

static void	whichPP(void) {
	which = (which + 1) % ARRAY_SIZE;
}

static void	printArray(void) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		std::cout << "Slot " << i << " animal goes: ";
		if (slots[i])
			animals[i]->makeSound();
		else
			std::cout << "nowhere, it doesn't exist yet\n";
	}
}

static void	cleanExit(void) {
	std::cout << "\nExit routine engaged. All existing animals will be desconstructed\n";

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (slots[i])
			delete animals[i];
	}
}

static void	safeAdd(int mode, std::string type) {
	bool	typeGiven = type != "TYPE_NOT_GIVEN";

	if (slots[which])
		delete animals[which];
	if (mode == BASIC) {
		if (typeGiven)
			animals[which] = new Animal(type);
		else
			animals[which] = new Animal;
	}
	else if (mode == CAT) {
		if (typeGiven)
			animals[which] = new Cat(type);
		else
			animals[which] = new Cat;
	}
	else if (mode == DOG) {
		if (typeGiven)
			animals[which] = new Dog(type);
		else
			animals[which] = new Dog;
	}
	slots[which] = true;
	whichPP();
}

static std::string	getType(int type) {
	std::string	input;
	std::string	typeName = type == 0 ? "animal" : (type == 1 ? "cat" : "dog");
	std::cout << "Do you want to describe the new " << typeName << "? [1.YES|2.NO]: ";

	while (1) {
		if (!std::getline(std::cin, input))
			return "EXIT_SIGNAL_GIVEN_BY_USER";
		if (input == "NO" || input == "2")
			return "TYPE_NOT_GIVEN";
		if (input == "YES" || input == "1") {
			while (1) {
				std::cout << "\nDescribe your new " << typeName << ": ";
				if (!std::getline(std::cin, input))
					return "EXIT_SIGNAL_GIVEN_BY_USER";
				return input;
			}
		}
	}
	return "EXIT_SIGNAL_GIVEN_BY_USER";
}

static std::string	copyOne(void) {
	int			toCopy;
	int			fromCopy;
	std::string	to;
	std::string	from;

	while (1) {
		std::cout << "Which slot in memory do you want to copy? [";

		for (int i = 0; i < ARRAY_SIZE; i++) {
			std::cout << (slots[i] ? C_GREEN : C_PINK);
			std::cout << i + 1 << ". " << (slots[i] ? "full" : "null") << (i == ARRAY_SIZE - 1 ? "" : " ");
		}
		std::cout << C_WHITE << "]: ";

		if (!std::getline(std::cin, from))
			return "EXIT_SIGNAL_GIVEN_BY_USER";

		fromCopy = from[0] - '0';

		if (fromCopy > 9 || fromCopy < 1) { continue ; }

		fromCopy--;

		if (fromCopy > ARRAY_SIZE) { std::cout << "Choose a number from 1 to " << ARRAY_SIZE + 1 << "\n"; continue ; }

		if (!slots[fromCopy]) { std::cout << "Can't copy from slot " << fromCopy + 1 << ": it is still empty!\n"; return "SUCCESS" ; }

		else
			break ;
	}
	while (1) {
		std::cout << "Which slot to copy slot " << fromCopy + 1 << " to? [";

		for (int i = 0; i < ARRAY_SIZE; i++) {
			std::cout << (slots[i] ? C_GREEN : C_PINK);
			if (i == fromCopy) {
				std::cout << C_BLUE << i + 1 << "from" << (i == ARRAY_SIZE - 1 ? "" : " ");
				continue ;
			}
			std::cout << i + 1 << ". " << (slots[i] ? "full" : "null") << (i == ARRAY_SIZE - 1 ? "" : " ");
		}
		std::cout << C_WHITE << "]: ";

		if (!std::getline(std::cin, to))
			return "EXIT_SIGNAL_GIVEN_BY_USER";

		toCopy = to[0] - '0';

		if (toCopy > 9 || toCopy < 1) { continue ; }

		toCopy--;

		if (fromCopy > ARRAY_SIZE) { std::cout << "Choose a number from 1 to " << ARRAY_SIZE + 1 << "\n"; continue ; }
		else
			break ;
	}

	animals[toCopy] = animals[fromCopy];
	slots[toCopy] = true;
	return "SUCCESS";
}

static std::string	deleteOne(void) {
	int			toDelete;
	std::string	input;

	while (1) {
		std::cout << "Which slot in memory do you want removed? [";

		for (int i = 0; i < ARRAY_SIZE; i++)
			std::cout << i + 1 << ". " << (slots[i] ? "full" : "null") << (i == ARRAY_SIZE - 1 ? "" : " ");

		std::cout << "]: ";

		if (!std::getline(std::cin, input))
			return "EXIT_SIGNAL_GIVEN_BY_USER";

		toDelete = input[0] - '0';

		if (toDelete > 9 || toDelete < 1)
			continue ;

		toDelete--;

		if (toDelete > ARRAY_SIZE) {
			std::cout << "Choose a number from 1 to " << ARRAY_SIZE + 1 << "\n";
			continue ;
		}

		if (!slots[toDelete]) {
			std::cout << "This slot isn't allocated yet, can't delete it!\n";
			break ;
		}

		else {
			std::cout << "Cleaning up slot " << toDelete + 1 << ":\n";
			delete animals[toDelete];
			slots[toDelete] = false;
			break ;
		}
	}
	return "SUCCESS";
}

int main() {
	int			type;
	std::string	command;
	std::string	subcommand;

	while (1) {
		std::cout << "Create an [1.ANIMAL|2.CAT|3.DOG] or choose to [4.DISPLAY|5.COPY|6.DELETE|7.EXIT]: ";

		if (!std::getline(std::cin, command) || command == "EXIT" || command == "7")
			break;

		if (command == "DISPLAY" || command == "4")
			printArray();

		if (command == "ANIMAL" || command == "1" || command == "CAT" || command == "2" || command == "DOG" || command == "3") {
			subcommand = getType(0);
			if (subcommand == "EXIT_SIGNAL_GIVEN_BY_USER")
				break ;
			if (command == "ANIMAL" || command == "1")
				type = 0;
			else if (command == "CAT" || command == "2")
				type = 1;
			else
				type = 2;
			safeAdd(type, subcommand);
		}

		if (command == "5" || command == "COPY") {
			subcommand = copyOne();
			if (subcommand == "EXIT_SIGNAL_GIVEN_BY_USER")
				break ;
		}

		if (command == "6" || command == "DELETE") {
			subcommand = deleteOne();
			if (subcommand == "EXIT_SIGNAL_GIVEN_BY_USER")
				break ;
		}
	}

	bool	needClean = false;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (slots[i])
			needClean = true;
	}
	if (needClean)
		cleanExit();
}

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook(void) {
	_total = 0;
	_nextIndex = 0;
}

PhoneBook::~PhoneBook(void) {
}

int	PhoneBook::_askIndex(void) const {
	int			index;
	char		junk;
	std::string	input;

	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return (-1);
	std::stringstream	stream(input);
	if (!(stream >> index))
		return (-1);
	if (stream >> junk)
		return (-1);
	return (index);
}

void	PhoneBook::_borderSummary(bool top) const {
	std::string	border;

	border += top ? "┌" : "└";

	for (int i = 0; i < 4; i++)
	{
		border += "──────────";

		if (i < 3)
			border += top ? "┬" : "┴";
	}

	border += top ? "┐" : "┘";
	std::cout << border << std::endl;
}

void	PhoneBook::_printSummaryLine(const std::string summary[4]) const {
	std::string	cutouts[4];

	for (int i = 0; i < 4; i++)
	{
		if (summary[i].length() > 10)
			cutouts[i] = summary[i].substr(0, 9) + ".";
		else
			cutouts[i] = summary[i];
	}
	std::cout << "│";
	for (int i = 0; i < 4; i++)
			std::cout << std::setw(10) << cutouts[i] << "│";
	std::cout << std::endl;
}

void	PhoneBook::add(void) {
	std::string	name;
	std::string	surname;
	std::string	nickname;
	std::string	number;
	std::string	secret;

	name = _prompt("First name");
	surname = _prompt("Last name");
	nickname = _prompt("Nickname");
	number = _prompt("Phone Number");
	secret = _prompt("Darkest Secret");

	_contacts[_nextIndex] = Contact(
			name, surname, nickname,
			number, secret, _nextIndex + 1
			);

	if (_total < 8)
		_total++;

	_nextIndex = (_nextIndex + 1) % 8;
}

void	PhoneBook::silentAdd(Contact c) {
	_contacts[_nextIndex] = c;

	if (_total < 8)
		_total++;
	_nextIndex = (_nextIndex + 1) % 8;
}

void	PhoneBook::search(void) {
	int			index;
	std::string	summary[4];

	if (_total == 0)
	{
		std::cout << "Phonebook empty. Try ADDing contacts!" << std::endl;
		return ;
	}

	_borderSummary(true);

	std::cout << "│  Index   │   Name   │   Sur.   │ Nickname │" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;

	for (int i = 0; i < _total; i++)
	{
		_contacts[i].getSummary(summary);
		_printSummaryLine(summary);
	}
	_borderSummary(false);

	index = _askIndex();
	if (index == -1)
		std::cout << "Error in index format." << std::endl;
	else if (index < 1 || index > _total)
		std::cout << "Index out of range." << std::endl;
	else
		std::cout << _contacts[index - 1].getCard() << std::endl;
}

std::string	PhoneBook::_prompt(const std::string& label) const {
	std::string	input;

	while (input.empty())
	{
		std::cout << label << ": ";
		if (!std::getline(std::cin, input))
			return ("");
		if (input.empty())
			std::cout << "Field '" << label << "' can't be empty" << std::endl;
	}
	return (input);
}

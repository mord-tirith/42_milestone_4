#include "Contact.hpp"
#include "Card.hpp"

Contact::Contact(const std::string& name, const std::string& surname,
		const std::string& nickname, const std::string& number,
		const std::string& secret) {
	_name = name;
	_surname = surname;
	_nickname = nickname;
	_number = number;
	_secret = secret;
}

std::string Contact::getCard(void) {
	std::string result;

	Card::SingleHeadedList details[] = {
		{"Name", _name,},
		{"Last Name", _surname},
		{"Nickname", _nickname},
		{"Phone Number", _number},
		{"Darkest Secret", _secret}
	};

	Card card(_name, details, 5);
	result = card.render();
	return (result);
} 

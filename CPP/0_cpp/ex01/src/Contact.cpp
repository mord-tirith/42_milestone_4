#include "Contact.hpp"
#include "Card.hpp"

Contact::Contact(void) {
	_name = "";
	_surname = "";
	_nickname = "";
	_number = "";
	_secret = "";
	_index = 0;
	_card = "";
}

Contact::Contact(const std::string& name, const std::string& surname,
		const std::string& nickname, const std::string& number,
		const std::string& secret, int index) {
	_name = name;
	_surname = surname;
	_nickname = nickname;
	_number = number;
	_secret = secret;
	_index = index;
	_card = _makeCard();
}

std::string Contact::_makeCard(void) const {
	std::string title;

	Card::SingleHeadedList details[] = {
		{"Name", _name,},
		{"Last Name", _surname},
		{"Nickname", _nickname},
		{"Phone Number", _number},
		{"Darkest Secret", _secret}
	};

	title += char(_index + '0');
	title += ". ";
	title += _name;
	Card card(title, details, 5);
	return (card.render());
}

void	Contact::getSummary(std::string summary[4]) const {
	std::string	index;

	index += char(_index + '0');
	summary[0] = index;
	summary[1] = _name;
	summary[2] = _surname;
	summary[3] = _nickname;
}

std::string	Contact::getCard(void) const {
	return (_card);
}

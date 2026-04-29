#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
	 public:
		 Contact(void);
		 Contact(
				 const std::string& name, const std::string& surname,
				 const std::string& nickname, const std::string& number,
				 const std::string& secret, int index);
		 void			getSummary(std::string buffer[4]) const;
		 std::string	getCard(void) const;

	private:
		 int			_index;
		 std::string	_name;
		 std::string	_nickname;
		 std::string	_surname;
		 std::string	_number;
		 std::string	_secret;
		 std::string	_card;

		 std::string	_makeCard(void) const;
};

#endif

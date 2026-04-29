#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
	 public:
		 Contact(
				 const std::string& name, const std::string& surname,
				 const std::string& nickname, const std::string& number,
				 const std::string& secret);
		 std::string getFirstName();
		 std::string getLastName();
		 std::string getNickname();
		 std::string getNumber();
		 std::string getDarkestSecret();
		 std::string getCard(void);

	private:
		 std::string _name;
		 std::string _nickname;
		 std::string _surname;
		 std::string _number;
		 std::string _secret;
};

#endif

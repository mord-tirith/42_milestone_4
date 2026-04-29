#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		int		_total;
		int		_nextIndex;
		Contact	_contacts[8];
	
		int			_askIndex(void) const;
		void		_printSummaryLine(const std::string summary[4]) const;
		void		_borderSummary(bool top) const;
		std::string	_prompt(const std::string& label) const;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	add(void);
		void	search(void);
};

#endif


#include "PhoneBook.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

static void print_tenchar_line(const std::string &s, bool last)
{
    if (s.length() > 10)
        std::cout << s.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << s;
    if (last)
        std::cout << std::endl;
    else
        std::cout << " | ";
}

static void print_complete(const Contact c)
{
    std::cout << "First Name:\n" << c.getFirstName() << "\n";
    std::cout << "Last Name:\n" << c.getLastName() << "\n";
    std::cout << "Nickname:\n" << c.getNickname() << "\n";
    std::cout << "Phone Number:\n" << c.getNumber() << "\n";
    std::cout << "Darkest Secret:\n" << c.getDarkestSecret() << std::endl;
}

static void print_summary(int i, const Contact c)
{
    std::ostringstream oss;
    oss << i;

    print_tenchar_line(oss.str(), false);
    print_tenchar_line(c.getFirstName(), false);
    print_tenchar_line(c.getLastName(), false);
    print_tenchar_line(c.getNickname(), true);
}

void    PhoneBook::searchContacts() const
{
    if (total == 0)
    {
        std::cout << "You have no contacts to display yet\n";
        std::cout << "Try creating one with the command ADD" << std::endl;
        return ;
    }
    for (int i = 0; i < total; i++)
        print_summary(i + 1, contacts[i]);
}

void    PhoneBook::displayContact(int index) const
{
    if (index < 1 || index > total)
        std::cout << "Invalid index" << std::endl;
    else
        print_complete(contacts[index - 1]);
}

void    PhoneBook::addContact(const Contact c)
{
    if (total < 8)
        total++;
    contacts[next_index++] = c;
    next_index %= 8;
}

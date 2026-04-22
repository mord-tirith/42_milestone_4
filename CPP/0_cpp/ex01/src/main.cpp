
#include "PhoneBook.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <unistd.h>

static void clearterm(int &count, bool tty)
{
    count = 1;
    if (!tty)
        return ;
    std::cout << "\033[2J\033[H";
}

static void ttylesslog(const std::string input)
{
    std::cout << "*USER INPUT:* " << input << std::endl;
}

static std::string query_one(std::string prompt, bool tty)
{
    std::string input = "";

    std::cout << prompt << "\n";
    while (input.empty())
    {
        if (!std::getline(std::cin, input))
            return ("");
    }
    if (!tty)
        ttylesslog(input);
    return (input);
}

static Contact  populate_contact(bool tty)
{
    Contact     c;
    std::string name;

    name = query_one("First name:", tty);
    c.setFirstName(name);
    name += "'s ";

    c.setLastName(query_one(name + "last name:", tty));
    c.setNickname(query_one(name + "nickname:", tty));
    c.setNumber(query_one(name + "phone number:", tty));
    c.setDarkestSecret(query_one(name + "darkest secret:", tty));
    return c;
}

int main(void)
{
    int         line_count = 2;
    int         line_lim = 50;
    bool        tty = isatty(STDOUT_FILENO);
    PhoneBook   book;
    std::string input = "";

    while (true)
    {
        std::cout << "ADD a new contact, SEARCH your existing contacts or EXIT phonebook" << std::endl;
        while (input.empty())
        {
            if (line_count > line_lim)
            {
                clearterm(line_count, tty);
                std::cout << "ADD, SEARCH or EXIT" << std::endl;
            }
            if (!std::getline(std::cin, input))
                return (0);
            line_count++;
        }
        if (!tty)
            ttylesslog(input);
        if (input == "EXIT")
            break ;
        else if (input == "ADD")
        {
            book.addContact(populate_contact(tty));
            line_count += 10;
        }
        else if (input == "SEARCH")
        {
            book.searchContacts();
            std::getline(std::cin, input);
            if (!tty)
                ttylesslog(input);
            book.displayContact(std::atoi(input.c_str()));
            line_count += book.getTotal() + 10;
            if (line_count > line_lim)
                line_count = line_lim - 1;
        }
        input = "";
    }
}

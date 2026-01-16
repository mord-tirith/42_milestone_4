
#pragma once
#include "Contact.hpp"

class PhoneBook
{
    private:
        int     total;
        int     next_index;
        Contact contacts[8];

    public:
        PhoneBook(): total(0), next_index(0) {}

        int     getTotal() const { return total ;}

        void    addContact(const Contact c);
        void    displayContact(int index) const;
        void    searchContacts() const;
};

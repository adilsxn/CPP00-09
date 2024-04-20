#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <string>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void incrementIndex(void);
        bool _add(void);
        bool addContact(Contact tmp);
        bool searchContact(void);
        bool showContact(int i);
        int getIndex(std::string input);
        int _index;
        
    private:
       int _nbContacts;
       Contact _List[8];
};

std::string  getInput(std::string input);
#endif


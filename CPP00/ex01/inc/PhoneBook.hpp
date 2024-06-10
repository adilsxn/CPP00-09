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
        bool addContact(void);
        bool searchContact(void);
        bool showContact(int i);
        bool showOneContact(int i);
        int getIndex(std::string input);
        int _index;
        
    private:
       int _nbContacts;
       Contact _List[7];
};

std::string  getInput(std::string input);
#endif


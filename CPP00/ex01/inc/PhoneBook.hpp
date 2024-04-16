#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void incrementIndex(void);
        std::string getInput(std::string input);
        bool _add(void);
        bool addContact(Contact tmp);
        bool searchContact(void);
        bool showContact(void);
        void exit(void);
        
    private:
       int _index;
       bool _on;
       int _nbContacts;
       Contact _List[8];
};
#endif


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
        bool addContact(void);
        bool searchContact(void);
        bool showContact(void);
        void exit(void);
        
    private:
       int index;
       bool on;
       Contact List[8];
};
#endif


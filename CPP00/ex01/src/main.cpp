#include "../inc/PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main (void)
{
    PhoneBook list;
    std::string input;

    std::cout << "Welcome to HellaPages PhoneBook\n";
    std::cout << "How may we help you ?\n";
    std::cout << "We provide the following options:\n";
    std::cout << "ADD - To add contacts to our list\n";
    std::cout << "SEARCH - To display all the contacts\n";
    std::cout << "EXIT - To exit the program\n";
    while(1)
    {
        input = getInput("option");
        if (!input.empty() && isStringAlpha(input))
        {
            if (input == "ADD" || input == "add")
                list._add();
            else if (input == "SEARCH" || input == "search")
                list.searchContact();
            else if (input == "EXIT" || input == "exit")
                list.exit();
            else
                std::cout << "We dont have this option\n";
        }
        else
            std::cout << "Sorry we don't this option\n";
    }
    return 0;
}

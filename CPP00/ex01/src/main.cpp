#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"
#include <iostream>
#include <cstdlib>

int main (void)
{
    PhoneBook list;
    std::string input;

    std::cout << "\t\tWelcome to HellaPages PhoneBook\n";
    std::cout << "\t\tHow may we help you ?\n";
    std::cout << "\t\tWe provide the following options:\n";
    std::cout << "\t\t\tADD - To add contacts to our list\n";
    std::cout << "\t\t\tSEARCH - To display all the contacts\n";
    std::cout << "\t\t\tEXIT - To exit the program\n";
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
                std::exit(0);
            else
                std::cout << "We dont have this option\n";
        }
        else
            std::cout << "Sorry we don't this option\n";
    }
    return 0;
}

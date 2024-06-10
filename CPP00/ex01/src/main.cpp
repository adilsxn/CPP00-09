#include "../inc/PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

int main (void)
{
    PhoneBook list;
    std::string input;

    std::cout << "\t\tWelcome to HellaPages PhoneBook\n";
    // std::cout << "\t\t\tADD - To add contacts to our list\n";
    // std::cout << "\t\t\tSEARCH - To display all the contacts\n";
    // std::cout << "\t\t\tEXIT - To exit the program\n";
    while(1)
    {

        std::cout <<"\n+------------------Main Menu-----------------+\n\n";
        input = getInput("an option");
        if (input == "ADD" || input == "add")
            list.addContact();
        else if (input == "SEARCH" || input == "search")
            list.searchContact();
        else if (input == "EXIT" || input == "exit")
            std::exit(0);
        else
        {
            std::cout<< "Please enter one of the options:"<<std::endl
                <<"\tADD\t: add a contact"<<std::endl
                <<"\tSEARCH\t: search for a contact"<<std::endl
                <<"\tADD\t: exit the HellaPages phonebook"<<std::endl;
        }
    }
    return 0;
}

#include "../inc/PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void): index(-1), on(true){
    return ;
};

PhoneBook::~PhoneBook(void)
{
    return ;
};

void PhoneBook::exit(void)
{
    this->on = false;
    return ;
}

void PhoneBook::incrementIndex(void)
{
    if (PhoneBook::index == 7)
        PhoneBook::index = 0;
    else
        PhoneBook::index++;
}

bool PhoneBook::addContact()
{
    incrementIndex();
    while (on)
    {
        PhoneBook::List[index].setFirstName(PhoneBook::getInput("First Name"));
        PhoneBook::List[index].setLastName(PhoneBook::getInput("Last Name"));
        PhoneBook::List[index].setNickName(PhoneBook::getInput("Nick Name"));
        PhoneBook::List[index].setPhoneNumber(PhoneBook::getInput("Phone Number"));
        PhoneBook::List[index].setDarkestSecret(PhoneBook::getInput("Secret"));
    }
    std::cout << "Contact added successfully\n";
    return true;
}

std::string trimSpace(std::string input)
{

}

std::string  PhoneBook::getInput(std::string input)
{
    std::string output;
    std::cout << "Please enter the" + input << std::endl;
    std::getline(std::cin, output);
    return (output);
}


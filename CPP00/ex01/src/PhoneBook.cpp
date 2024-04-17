#include "../inc/PhoneBook.hpp"
#include "Contact.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>

PhoneBook::PhoneBook(void): _index(-1), _on(true), _nbContacts(-1){
    return ;
};

PhoneBook::~PhoneBook(void)
{
    return ;
};

void PhoneBook::exit(void)
{
    this->_on = false;
    return ;
}

void PhoneBook::incrementIndex(void)
{
    if (PhoneBook::_index == 7)
        PhoneBook::_index = 0;
    else
        PhoneBook::_index++;
}

bool PhoneBook::_add(void)
{
    Contact tmp;

    std::cout << "Please add the details to create a contact\n";
    std::cout << "The details cannot either space or empty\n";
    tmp.setFirstName(PhoneBook::getInput("First Name"));
    tmp.setLastName(PhoneBook::getInput("Last Name"));
    tmp.setNickName(PhoneBook::getInput("Nick Name"));
    tmp.setPhoneNumber(PhoneBook::getInput("Phone Number"));
    tmp.setDarkestSecret(PhoneBook::getInput("Secret"));
    PhoneBook::addContact(tmp);
    return true;
}

bool PhoneBook::addContact(Contact tmp)
{
    incrementIndex();
    PhoneBook::_List[_index] = tmp;
    std::cout << "Contact added successfully\n";
    return true;
}

std::string trimSpace(std::string input)
{
    input.erase(input.find_last_not_of(' ')+1);
    input.erase(input.find_first_not_of(' '));
    return input;
}

std::string getInput(std::string input)
{
    std::string output;
    std::cout << "Please enter the" + input << std::endl;
    std::getline(std::cin, output);
    if (std::cin.eof())
        std::exit(EXIT_SUCCESS);
    return (trimSpace(output));
}

static std::string Trunc(std::string s)
{
    if (s.length() > 9)
        s = s.substr(0, 9) + ".";
    return (s);
}

bool PhoneBook::showContact(int i)
{
    std::cout << std::right << std::setw(10)<< i << "|";
    std::cout << std::right << std::setw(10)<< Trunc(PhoneBook::_List[i].getFirstName()) << "|";
    std::cout << std::right << std::setw(10)<< Trunc(PhoneBook::_List[i].getLastName())<< "|";
    std::cout << std::right << std::setw(10)<< Trunc(PhoneBook::_List[i].getNickName())<< "|" 
    <<std::endl;
    return true;
}

int PhoneBook::getIndex(std::string input)
{
    int index = -1;

    index = std::atoi(input.c_str());
   if (input.empty() || isStringDigit(input) ||  index < 0 || index > _index)
   {
        std::cout << "Wrong index\n";
   }
   return index;
};

bool PhoneBook::searchContact()
{
    int index = -1;

    if (PhoneBook::_index == -1)
        return std::cout<< "There are no contacts to display\n";

    std::cout << std::right << std::setw(10)<< "Index" << "|";
    std::cout << std::right << std::setw(10)<< "Fist Name" << "|";
    std::cout << std::right << std::setw(10)<< "Last Name" << "|";
    std::cout << std::right << std::setw(10)<< "Nickname" << "|" <<std::endl;
    for (int i = 0; i < 8; i++)
        PhoneBook::showContact(i);
    index = getIndex(getInput("Index"));
    if (index > 0)
        showContact(index);
    return true;
}




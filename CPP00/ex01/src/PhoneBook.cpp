#include "../inc/PhoneBook.hpp"
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

std::string  PhoneBook::getInput(std::string input)
{
    std::string output;
    std::cout << "Please enter the" + input << std::endl;
    std::getline(std::cin, output);
    return (trimSpace(output));
}

bool PhoneBook::searchContact()
{
    std::cout << std::setw(10)<< std::right << "Index" << "|";
    std::cout << std::setw(10)<< std::right << "Fist Name" << "|";
    std::cout << std::setw(10)<< std::right << "Last Name" << "|";
    std::cout << std::setw(10)<< std::right << "Nickname" << "|" <<std::endl;
    for (int i = 0; i < 9; i++)
    {
        std::cout << std::setw(10)<< i << "|";
        std::cout << std::setw(10)<< PhoneBook::_List[i].getFirstName()<< "|";
        std::cout << std::setw(10)<< PhoneBook::_List[i].getLastName()<< "|";
        std::cout << std::setw(10)<< PhoneBook::_List[i].getNickName()<< "|" 
        <<std::endl;
    }

    return true;
}




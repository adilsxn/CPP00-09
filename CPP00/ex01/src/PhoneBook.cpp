#include "../inc/PhoneBook.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>

PhoneBook::PhoneBook(void): _index(-1), _nbContacts(-1){
    return ;
};

PhoneBook::~PhoneBook(void)
{
    return ;
};

void PhoneBook::incrementIndex(void)
{
    PhoneBook::_index++;
    if (PhoneBook::_index > 7)
    {
        PhoneBook::_index = 0;
        PhoneBook::_nbContacts--;
    }
}

bool PhoneBook::addContact(void)
{
    std::cout <<"\n+------------------New Contact Menu-----------------+\n\n";
    this->incrementIndex();
    while(1)
    {
        if (this->_List[_index].setFirstName(getInput("the first name:")) == true)
            break;
    }
    while(1)
    {
       if (this->_List[_index].setLastName(getInput("the last name:")) == true)
           break;
    }
    while(1)
    {
        if(this->_List[_index].setNickName(getInput("the nickname:")) ==  true)
            break;
    }
    while(1)
    {
        if(this->_List[_index].setPhoneNumber(getInput("the phone number:")) == true)
            break;
    }
    while(1)
    {
        if(this->_List[_index].setDarkestSecret(getInput("the darkest secret:")) == true)
            break;
    }
    std::cout << "Contact added\n";
    _nbContacts++;
    return true;
}

std::string trimSpace(std::string input)
{
    const char* s = " \t\n\r\f\v";
    int end  =  input.find_last_not_of(s);
    int start =  input.find_first_not_of(s);
    if (start == end)
        return input;
    return input.substr(start, end - start + 1);
}

std::string getInput(std::string input)
{
    std::string output;
    std::cout <<"Please enter "<<input<<std::endl<<"> ";
    if (!std::getline(std::cin, output) || std::cin.eof())
    {
        std::cout << std::endl;
        return (std::string());
    }
    output = trimSpace(output);
    return output;
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

bool PhoneBook::showOneContact(int i){
    std::cout <<"-First Name    : "<<PhoneBook::_List[i].getFirstName()<< std::endl;
    std::cout <<"-Last Name     : "<<PhoneBook::_List[i].getLastName()<< std::endl;
    std::cout <<"-NickName      : "<<PhoneBook::_List[i].getNickName()<< std::endl;
    std::cout <<"-Phone number  : "<<PhoneBook::_List[i].getPhoneNumber()<< std::endl;
    std::cout <<"-Darkest Secret: "<<PhoneBook::_List[i].getDarkestSecret()<< std::endl;
    return true;
}

int PhoneBook::getIndex(std::string input)
{
    int index = -1;
    if (!input.empty() && isStringAlpha(input) == false)
        index = std::atoi(input.c_str());
    if (index < 0 || index > _index )
        return std::cout << "No contact at the index\n", -1;
   return index;
};

bool PhoneBook::searchContact()
{
    int index = -1;

    std::cout <<"\n+------------------Search Menu-----------------+\n\n";
    if (_index < 0)
        return std::cout << "No contacts to display, please add one first\n", false;
    std::cout << std::right << std::setw(10)<< "Index" << "|";
    std::cout << std::right << std::setw(10)<< "Fist Name" << "|";
    std::cout << std::right << std::setw(10)<< "Last Name" << "|";
    std::cout << std::right << std::setw(10)<< "Nickname" << "|" <<std::endl;
    for (int i = 0; i <= _nbContacts; i++)
        PhoneBook::showContact(i);
    index = getIndex(getInput("the index of the contact to display"));
    if (index >= 0)
        showOneContact(index);
    return true;
}




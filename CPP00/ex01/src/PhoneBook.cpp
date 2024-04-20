#include "../inc/PhoneBook.hpp"
#include "../inc/Contact.hpp"
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
    if (PhoneBook::_index == 3)
        PhoneBook::_index = 0;
    else
        PhoneBook::_index++;
}

bool PhoneBook::_add(void)
{
    Contact tmp;

    std::cout << "Please add the details to create a contact\n";
    std::cout << "The details cannot have spaces or be  empty\n";
    tmp.setFirstName(getInput("First Name"));
    tmp.setLastName(getInput("Last Name"));
    tmp.setNickName(getInput("Nick Name"));
    tmp.setPhoneNumber(getInput("Phone Number"));
    tmp.setDarkestSecret(getInput("Secret"));
    PhoneBook::addContact(tmp);
    return true;
}


bool PhoneBook::addContact(Contact tmp)
{
    if (tmp.getFirstName().empty() 
        || tmp.getLastName().empty()
        || tmp.getNickName().empty()
        || tmp.getPhoneNumber().empty()
        || tmp.getDarkestSecret().empty())
    {
        std::cout << "Contact added unsuccessfully\n";
        std::cout << "One of the fields was empty\n";
        return false;
    }
    incrementIndex();
    PhoneBook::_List[_index] = tmp;
    std::cout << "Contact added successfully\n";
    return true;
}

std::string trimSpace(std::string input)
{
    const char* s = " \t\n\r\f\v";
    int end  =  input.find_last_not_of(s) + 1;
    int start =  input.find_first_not_of(s);
    if (start == end)
        return input;
    return input.substr(start, end - start + 1);
}

std::string getInput(std::string input)
{
    std::string output;
    std::cout << "Please enter the " << input << "\n";
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

    if (input.empty() && isStringDigit(input))
        return std::cout << "Wrong index\n", index;
    index = std::atoi(input.c_str());
    if (index < 0 || index > _index )
        return std::cout << "Wrong index\n", -1;
   return index;
};

bool PhoneBook::searchContact()
{
    int index = -1;

    if (_index < 0)
        return std::cout << "There are no contacts to display\n", false;

    std::cout << std::right << std::setw(10)<< "Index" << "|";
    std::cout << std::right << std::setw(10)<< "Fist Name" << "|";
    std::cout << std::right << std::setw(10)<< "Last Name" << "|";
    std::cout << std::right << std::setw(10)<< "Nickname" << "|" <<std::endl;
    for (int i = 0; i <= _index; i++)
        PhoneBook::showContact(i);
    index = getIndex(getInput("Index"));
    if (index > 0)
        showContact(index);
    return true;
}




#include "../inc/Contact.hpp"
#include <cctype>
#include <iostream>

Contact::Contact(void): FirstName(""),
                        LastName(""),
                        NickName(""),
                        PhoneNumber(""),
                        DarkestSecret("") {
return ;
}

Contact::~Contact(void)
{
    return ;
}

bool Contact::setFirstName(std::string const str)
{
    if (str.empty())
        return false;
    else if (isStringAlpha(str) == false)
    {
        std::cout << "The string should not contains ";
        std::cout << "numbers, hyphens or spaces\n";
        return (false);
    }
    this->FirstName = str;
    return (true);
};

bool Contact::setLastName(std::string const str)
{
    if (str.empty())
        return false;
    else if (isStringAlpha(str) == false)
    {
        std::cout << "The string should not contains ";
        std::cout << "numbers, hyphens or spaces\n";
        return (false);
    }
    this->LastName = str;
    return (true);
};

bool Contact::setNickName(std::string const str)
{
    if (str.empty())
        return false;
    else if (isStringAlpha(str) == false)
    {
        std::cout << "The string should not contains ";
        std::cout << "numbers, hyphens or spaces\n";
        return (false);
    }
    this->NickName =  str;
    return (true);
};

bool Contact::setPhoneNumber(std::string const str)
{
    if (str.empty())
        return false;
    else if (isStringDigit(str) == false)
    {
        std::cout << "The string should only contain digits\n";
        return (false);
    }
    this->PhoneNumber =  str;
    return (true);
};

bool Contact::setDarkestSecret(std::string const str)
{
    if (str.empty())
        return false;
    else if (isStringAlpha(str) == false)
    {
        std::cout << "The string should not contains ";
        std::cout << "numbers, hyphens or spaces\n";
        return (false);
    }
    this->DarkestSecret =  str;
    return (true);
};



std::string Contact::getFirstName(void)const
{
    return this->FirstName;
};

std::string Contact::getLastName(void)const
{
    return this->LastName;
};

std::string Contact::getNickName(void)const
{
    return this->NickName;
}

std::string Contact::getPhoneNumber(void)const
{
    return this->PhoneNumber;
};

std::string Contact::getDarkestSecret(void)const
{
    return this->DarkestSecret;
};

bool isStringAlpha(std::string const str)
{
    std::string::const_iterator it = str.begin();
    for (; it < str.end(); it++)
        if (!std::isalpha(*it) || *it == ' ' || *it == '-')
            return (false);
    return (true);
};

bool isStringDigit(std::string const str)
{
    std::string::const_iterator it = str.begin();
    for (; it < str.end(); it++)
        if (!std::isdigit(*it) || *it == ' ' || *it == '-')
            return (false);
    return (true);
};


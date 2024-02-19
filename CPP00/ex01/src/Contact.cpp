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
        std::cout << "The string should not contains  \
                    numbers, hyphens or spaces" << std::endl;
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
        std::cout << "The string should not contains  \
                    numbers, hyphens or spaces" << std::endl;
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
        std::cout << "The string should not contains  \
                    numbers, hyphens or spaces" << std::endl;
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
        std::cout << "The string should only contain digits" << std::endl;
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
        std::cout << "The string should not contains  \
                    numbers, hyphens or spaces" << std::endl;
        return (false);
    }
    this->DarkestSecret =  str;
    return (true);
};

bool Contact::isStringAlpha(std::string const str)
{
    std::string::const_iterator it = str.begin();
    for (; it < str.end(); it++)
        if (!std::isalpha(*it) || *it == ' ' || *it == '-')
            return (false);
    return (true);
};

bool Contact::isStringDigit(std::string const str)
{
    std::string::const_iterator it = str.begin();
    for (; it < str.end(); it++)
        if (!std::isdigit(*it) || *it == ' ' || *it == '-')
            return (false);
    return (true);
};


#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
        //setters
        bool setFirstName(std::string const str);
        bool setLastName(std::string const str);
        bool setNickName(std::string const str);
        bool setPhoneNumber(std::string const str);
        bool setDarkestSecret(std::string const str);
        //getters
        std::string getFirstName(void)const;
        std::string getLastName(void)const;
        std::string getNickName(void)const;
        std::string getPhoneNumber(void)const;
        std::string getDarkestSecret(void)const;

    private: 
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
        bool isStringAlpha(std::string const str);
        bool isStringDigit(std::string const str);
};

#endif

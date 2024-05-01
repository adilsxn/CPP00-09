#include "../inc/Fixed.hpp"
#include <iostream>

//Default constructor
Fixed::Fixed(void):_raw(0)
{
    std::cout << "Default constructor called\n";
    return ;
}

//Destructor
Fixed::~Fixed(void)
{
    std::cout << "Destructor called\n";
    return ;
}

//Copy constructor
Fixed::Fixed(Fixed const& src)
{
    std::cout <<"Copy constructor called\n";
    *this = src;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Copy assignment operator called\n";
    if ( this != &rhs)
        this->_raw = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void)const
{
    std::cout << "getrawbits member function called\n";
    return this->_raw;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called\n";
    this->_raw = raw;
}


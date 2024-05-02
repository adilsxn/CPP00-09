#include "../inc/Fixed.hpp"
#include <cmath>
#include <ostream>

Fixed::Fixed(void):_raw(0){
    std::cout << "Default constructor called\n";
    return ;
}

Fixed::Fixed(int const n): _raw(n << _frac){
    std::cout << "Int constructor called\n";
    return ;
}

Fixed::Fixed(float const f): _raw(roundf(f * (1 << this->_frac)))
{
    std::cout << "Float constructor called\n";
    return ;
}

Fixed::~Fixed(void){
    std::cout << "Destructor called\n";
    return ;
}

Fixed::Fixed(Fixed const& src){
    std::cout << "Copy constructor called\n";
    *this = src;
}

Fixed& Fixed::operator=(Fixed const& rhs){
    std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        this->_raw = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void)const{
    return this->_raw;
}

void Fixed::setRawBits(int const raw){
    this->_raw = raw;
}

int Fixed::toInt(void)const{
    return this->_raw >> _frac;
}

float Fixed::toFloat(void)const{
    return (float) this->_raw / (float) (1 << this->_frac);
}

std::ostream& operator<<(std::ostream& o, Fixed const& fixed){
    o << fixed.toFloat();
    return o;
}



#include "../inc/Fixed.hpp"
#include <cmath>
#include <ostream>

Fixed::Fixed(void):_raw(0){
    // std::cout << "Default constructor called\n";
    return ;
}

Fixed::Fixed(int const n): _raw(n << this->_frac){
    // std::cout << "Int constructor called\n";
    return ;
}

Fixed::Fixed(float const f): _raw((int)roundf(f * (1 << this->_frac)))
{
    // std::cout << "Float constructor called\n";
    return ;
}

Fixed::~Fixed(void){
    // std::cout << "Destructor called\n";
    return ;
}

Fixed::Fixed(Fixed const& src){
    // std::cout << "Copy constructor called\n";
    *this = src;
}

Fixed& Fixed::operator=(Fixed const& rhs){
    // std::cout << "Copy assignment operator called\n";
    if (this != &rhs)
        this->_raw = rhs.getRawBits();
    return *this;
}

bool Fixed::operator< (Fixed const& rhs)const
{
    return this->_raw < rhs.getRawBits();
}

bool Fixed::operator> (Fixed const& rhs)const
{
    return this->_raw > rhs.getRawBits();
}

bool Fixed::operator>= (Fixed const& rhs)const
{
    return this->_raw >= rhs.getRawBits();
}
bool Fixed::operator<= (Fixed const& rhs)const
{
    return this->_raw <= rhs.getRawBits();
}

bool Fixed::operator== (Fixed const& rhs)const
{
    return this->_raw == rhs.getRawBits();
}

bool Fixed::operator!= (Fixed const& rhs)const
{
    return this->_raw != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const& rhs)
{
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const& rhs)
{
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const& rhs)
{
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const& rhs)
{
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator--(void)
{
    this->_raw -= 1;
    return *this;
}

Fixed& Fixed::operator++(void)
{
    this->_raw += 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old (*this);
    this->_raw -= 1;
    return old;
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    this->_raw += 1;
    return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return a < b ? a : b;
}

Fixed const& Fixed::min(Fixed const& a, Fixed const& b)
{
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return a > b ? a : b;
}
Fixed const& Fixed::max(Fixed const& a, Fixed const& b)
{
    return a > b ? a : b;
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



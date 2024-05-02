#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int _raw;
        static int const _frac = 8; 

    public:
        Fixed(void);
        Fixed(int const n);
        Fixed(float const f);
        ~Fixed(void);
        Fixed(Fixed const& src);
        Fixed& operator=(Fixed const& rhs);
        bool operator< (Fixed const& rhs)const;
        bool operator> (Fixed const& rhs)const;
        bool operator>= (Fixed const& rhs)const;
        bool operator<= (Fixed const& rhs)const;
        bool operator== (Fixed const& rhs)const;
        bool operator!= (Fixed const& rhs)const;

        Fixed operator+(Fixed const& rhs);
        Fixed operator-(Fixed const& rhs);
        Fixed operator*(Fixed const& rhs);
        Fixed operator/(Fixed const& rhs);

        Fixed& operator--(void);
        Fixed& operator++(void);
        Fixed operator--(int);
        Fixed operator++(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static Fixed const& min(Fixed const& a, Fixed const& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static Fixed const& max(Fixed const& a, Fixed const& b);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& o, Fixed const& fixed);

#endif

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    public:
        Fixed(void);
        Fixed(int const n);
        Fixed(float const f);
        ~Fixed(void);
        Fixed(Fixed const& src);
        Fixed& operator=(Fixed const& rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int _raw;
        static int const _frac = 8; 
};

std::ostream& operator<<(std::ostream& o, Fixed const& fixed);

#endif

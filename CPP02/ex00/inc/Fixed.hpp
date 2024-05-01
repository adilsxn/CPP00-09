#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    public:
        //constructor
        Fixed(void);
        //destructor
        ~Fixed(void);
        //copy constructor
        Fixed(Fixed const& src);
        //copy assignment overload
        Fixed& operator=(Fixed const& rhs);
        int getRawBits(void)const;
        void setRawBits(int const raw);
    private:
        int _raw;
        static const int _frac = 8;
};
#endif

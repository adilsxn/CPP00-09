#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
class ScalarConverter{
    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const& src);
        ScalarConverter& operator=(ScalarConverter const& rhs);
        ~ScalarConverter(void);
    public:
        static void convert(std::string const& input);
};
#endif

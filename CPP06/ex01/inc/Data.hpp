#ifndef DATA_HPP
#define DATA_HPP

#include<string>

class Data {
public:
    Data(void);
    Data(std::string& input);
    Data(const Data & src);
    Data &operator=(const Data & rhs);
    ~Data();
    std::string name;
    int age;
};

#endif // !DATA_HPP

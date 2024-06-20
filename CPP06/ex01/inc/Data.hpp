#ifndef DATA_HPP
#define DATA_HPP

#include<string>

class Data {
public:
    Data(void);
    Data(Data const& src);
    Data &operator=(Data const& rhs);
    ~Data();
    std::string name;
    int age;
};

#endif // !DATA_HPP

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string& stringREF = str;


    std::cout << "Welcome ladies, gentlemans and enbyes\n";
    std::cout << "-------------------///ADDRESS///-------------------\n";
    std::cout << "The memory address of the string" << &str << "\n";
    std::cout << "The memory address held by the pointer" << stringPTR << "\n";
    std::cout << "The memory address held by the refence" << &stringREF << "\n";
    std::cout << "-------------------///VALUE///-------------------\n";
    std::cout << "The value of the string: " << str << "\n";
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << "\n";
    std::cout << "The value pointed to by stringREF: " << stringREF << "\n";
    std::cout << "Goodbye ladies, gentlemans and enbyes\n";
}

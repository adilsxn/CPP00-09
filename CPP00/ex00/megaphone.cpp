#include <iostream>
#include <cctype>

int main (int argc, char* argv[])
{
    if (argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j] != '\0'; j++)
                argv[i][j] = toupper(argv[i][j]);
            std::cout << argv[i];
        }
        std::cout << "\n";
    }
    else
        std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"; 
}

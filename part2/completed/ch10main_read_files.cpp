#include <iostream>
#include <fstream>
#include <string>
#include <vector>

static const std::string OutFile = "out.txt";

void read_names(std::string& fn1, std::string& fn2)
{
    std::cout << "Enter first file name to read: ";
    std::cin >> fn1;
    std::cout << "second file name: ";
    std::cin >> fn2;
}

int main() 
{
    std::string fn1;
    std::string fn2;
    read_names(fn1, fn2);

    std::ifstream ist{fn1};
    std::ofstream ost{OutFile};
    char c;
    while (ist.get(c))
    {
        ost << c;
    };

    ist.close();
    ist.open(fn2);

    while (ist.get(c))
    {
        ost << c;
    };

    std::cout << '\n' << fn1 << " " << fn2;
    return 0;
}
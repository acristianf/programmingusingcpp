#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

static const std::string FileName = "numbers.txt";

void error(std::string msg, std::string fn = "")
{
    throw std::runtime_error(msg + fn);
}

void fill_vector(std::istream& ist, std::vector<int>& v)
{
    if (ist.eof()) return;
    else if (ist.bad()) error("ist is bad");
    else if (ist.fail()) {
        ist.get();
        ist.clear();
        fill_vector(ist, v);
    }

    for (int n; ist >> n;) v.push_back(n);
}

int main()
{
    std::vector<int> numbers;
    std::ifstream ist{FileName};
    if (!ist) error("couldn't open file ", FileName);
    fill_vector(ist, numbers);

    int sum = 0;
    sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << sum << '\n';

    std::cout << "Program executed successfully..." << '\n';
    return 0;
}
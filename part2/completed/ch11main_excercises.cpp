/* Actual página 440 - ejercicios */
#include <ctype.h>
#include <ios>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

#include "error.h"

// Excercise 11.1
void to_lower_file(const std::string& fn_in, const std::string& fn_out)
{
    std::ifstream ifs{fn_in};

    try { if(!ifs) error("couldn't open file ", fn_in); } 
    catch (std::runtime_error e) { std::cout << e.what(); }

    std::ofstream ofs{fn_out};

    std::string line;
    for (char c; ifs.get(c); ) {
        line += tolower(c);
    }
    ofs << line;
}

bool word_in_line(const std::string& line, const std::string& word)
{
    std::string temp{""};
    for (auto c : line) {
        if (isspace(c) || ispunct(c)) {
            if (temp.size() != 0 && temp == word) {
                return true;
            }
            temp.clear();
        } else {
            temp += c;
        }
    }
    return false;
}

// Excercise 11.2
void write_line_and_numbers(const std::string& fn_in, const std::string& fn_out, const std::string& word)
{
    std::ifstream ifs{fn_in};
    try { if(!ifs) error("couldn't open file ", fn_in); } 
    catch (std::runtime_error e) { std::cout << e.what(); }

    std::ofstream ofs{fn_out};

    std::string line;
    int line_number = 0;
    while (std::getline(ifs, line)) {
        ++line_number;
        if (word_in_line(line, word)) {
            ofs << line_number << " " << line << '\n';
        }
    };
}

// Excercise 11.4
void multi_input() {
    std::string num;
    std::vector<std::string> nums;
    while (std::cin >> num)
        nums.push_back(num);

    for (auto n : nums) {
        if (n[0] == '0') {
            if (n[1] == 'x') {
                int decimal = std::stoi(n, 0, 16);
                std::cout << n << "\thexadecimal" << std::setw(16) 
                               << "\tconverts to" << std::setw(5) << decimal << std::setw(10) << "decimal\n";
            } else {
                int decimal = std::stoi(n, 0, 8);
                std::cout << n << "\toctal" << std::setw(16)  
                               << "\tconverts to" << std::setw(5) << decimal << std::setw(10) << "decimal\n";
            }
        } else {
            std::cout << n << "\tdecimal" << std::setw(16)  
                        << "\tconverts to" << std::setw(5) << n << std::setw(10) << "decimal\n";
        }
    }    
}

// Excercise 11.6
void replace_with_whitespace(const std::string& whitespace, std::string& str)
{
    std::stringstream ss {str};
    str.clear();
    for (char c; ss.get(c); ) {
        for (auto w : whitespace)
            if (c == w) 
                c = ' '; 
        str += c;
    }
}

template<class T>
char* as_bytes(T& i)
{
    void* addr = &i;
    return static_cast<char*>(addr);
}

// Excercise 11.9
void text_to_binary(const std::string& f_in, const std::string& f_out)
{
    std::ifstream ist {f_in};
    try { if (!ist) error("can't open file ", f_in); }
    catch (std::runtime_error e) { std::cerr << e.what(); }

    std::ofstream ost {f_out, std::ios_base::binary};
    for (char x; ist.read(as_bytes(x), sizeof(char)); ) {
        ost.write(as_bytes(x), sizeof(char));
    }
}

// Excercise 11.12
void reverse_text_file(const std::string& fn)
{
    std::ifstream ist {fn};
    try { if (!ist) error("can't open file ", fn); }
    catch (std::runtime_error e) { std::cerr << e.what(); }

    std::string line;
    std::vector<std::string> lines;
    while (std::getline(ist, line)) {
        for (size_t i = 0; i < line.size() / 2; ++i) {
            char ch = line[i];
            line[i] = line[line.size() - 1 - i];
            line[line.size() - 1 - i] = ch;
        }
        lines.push_back(line);
    }

    ist.close();

    std::ofstream ost {fn};

    if (lines.size() != 0) {
        for (int i = lines.size(); i > 0; --i) {
            ost << lines[i-1] << '\n';
        }
    }
}

int main()
{
    return 0;
}
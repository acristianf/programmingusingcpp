/* Actual - pag 421 */
#include <cctype>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

#include "error.h"

class Punct_stream {
    public:
        Punct_stream(std::istream& is) : source{is}, sensitive{true} {}
        void whitespace(const std::string& s) { white = s; }
        void add_white(char c) { white += c; }
        bool is_whitespace(char c) {
            for (auto w : white)
                if (w == c) return true;
            return false;
        }
        void case_sensitive(bool b) { sensitive = b; }

        Punct_stream& operator>>(std::string& s) {
            while (!(buffer >> s)) {
                if (buffer.bad() || !source.good()) return *this;
                buffer.clear();

                std::string line;
                std::getline(source, line);

                for (char& ch : line) {
                    if (is_whitespace(ch)) {
                        ch = ' ';
                    } else if (!sensitive) {
                        ch = tolower(ch);
                    }
                }
                buffer.str(line);
            }
            return *this;
        };
        operator bool() const { return !(source.fail() || source.bad()) && source.good(); }
    
    private:
        std::istream& source;
        std::istringstream buffer;
        std::string white;
        bool sensitive;
};

double str_to_double(std::string s)
{
    std::istringstream is {s};
    double d;
    is >> d;
    if (!is) error("double format error: ", s);
    return d;
}

void get_words(const std::string& line, std::vector<std::string>& words)
{
    std::stringstream ss {line};
    std::string word {""};
    for (char c; ss.get(c);)
    {
        if (std::isspace(c) || std::ispunct(c)) {
            if (word.size() != 0) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
}


int main()
{
    Punct_stream ps {std::cin};
    ps.whitespace(".,;:");
    ps.case_sensitive(false);

    std::vector<std::string> words;
    for (std::string word; ps >> word; ) {
        words.push_back(word);
    }

    std::sort(words.begin(), words.end());
    std::cout << "[";
    for (int i = 0; i < words.size(); ++i) {
        if (i == 0 || words[i] != words[i-1]) {
            std::cout << words[i] << ' ';
        }
    }
    std::cout << "]\n";

    return 0;
}
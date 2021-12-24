/* 
    Practice folder and files for part 2 of Programming using c++ 2nd edition, this part
    is about I/O.
 */

#include <cctype>
#include <ctype.h>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

static const std::string FileName = "points.txt";

void error(std::string msg)
{
    throw std::runtime_error(msg);
}

void error(std::string msg, std::string fn)
{
    throw std::runtime_error(msg + fn);
}

struct Point {
    int x;
    int y;

    bool operator==(const Point& rhs) const
    {
        return x == rhs.x && y == rhs.y;
    }
    bool operator!=(const Point& rhs) const
    {
        return x != rhs.x || y != rhs.y;
    }
};

bool equal(const std::vector<Point>& v1, const std::vector<Point>& v2) 
{
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) 
            return false; 
    } 
    return true;
}

void display(std::ostream& ost, const std::vector<Point>& original, const std::vector<Point>& processed)
{
    if (!ost) error("couldn't open stream");
    if (original.size() != processed.size() || !equal(original, processed)) {
        ost << "Something's wrong!" << '\n';
        return;
    }
    for (size_t i = 0; i < original.size(); ++i) 
        ost << '(' << original[i].x << ',' << original[i].y << ')' << ' ' 
            << '(' << processed[i].x << ',' << processed[i].y << ')' << '\n';
}


std::istream& skip_to_int(std::istream& ist)
{
    for (char ch; ist >> ch; ) {
        if (std::isdigit(ch) || ch == '-') {
            ist.unget();
            return ist;
        }
    }
    return ist;
}

int main()
{
    std::vector<Point> original_points;

    // load 7 points into the vector
    for (int i = 0; i < 3; ++i)
    {
        Point p;
        std::cin >> p.x >> p.y; 
        original_points.push_back(p);
    }

    // format them into a file
    std::ofstream of{FileName};
    for (auto p : original_points)
        of << '(' << p.x << ',' << p.y << ')' << '\n';    

    of.close();

    std::ifstream ifs{FileName};
    std::vector<Point> processed_points = {};
    while (skip_to_int(ifs))
    {
        Point p = {};
        ifs >> p.x;
        // jump over ,
        ifs.get();
        ifs >> p.y;
        processed_points.push_back(p);
    }

    display(std::cout, original_points, processed_points);

    std::cout << "exit successful...";
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

static const std::string FileName = "raw_temps.txt";

struct Reading {
    int hour;
    double temperature;

    bool operator<=(const Reading& rhs) const {
        return rhs.temperature <= temperature;
    }
    bool operator<(const Reading& rhs) const {
        return rhs.temperature < temperature;
    }
    bool operator>=(const Reading& rhs) const {
        return rhs.temperature >= temperature;
    }
    bool operator>(const Reading& rhs) const {
        return rhs.temperature > temperature;
    }
};

void fill_vector(std::istream& ist, std::vector<Reading>& v)
{
    int hour;
    double temp;
    while (ist >> hour >> temp)
    {
        Reading r = {hour, temp};
        v.push_back(r);
    }
}

double median(std::vector<Reading>& v)
{
    size_t size = v.size();
    if (size == 0) 
        return 0;
    return size % 2 == 0 ? (v[size/2].temperature + v[size/2].temperature) / 2 : v[size/2].temperature;
}

int main()
{

    std::vector<Reading> readings;
    std::ifstream ist{FileName};
    fill_vector(ist, readings);

    sort(readings.begin(), readings.end());
    for (auto r : readings) std::cout << r.temperature << '\n';
    // std::cout << median(readings);

    return 0;
}
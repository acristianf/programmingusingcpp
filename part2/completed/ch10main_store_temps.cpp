#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <random>

static const std::string FileName = "raw_temps.txt";

struct Reading {
    int hour;
    double temperature;
};

int main()
{
    std::ofstream ost{FileName};
    std::vector<Reading> readings;

    Reading r;
    for (int i = 0; i < 50; ++i) {
        r.hour = i % 24;
        r.temperature = 50. / (rand() % 10 + 1);
        readings.push_back(r);
    }

    for (auto r : readings) 
        ost << r.hour << ' ' << r.temperature << '\n';
    
    return 0;
}
#include <iostream>
#include <cmath>
#include <fstream>
#include <regex>

int main()
{
    double time; double record;

    std::ifstream infile("input.txt");

    int i = 0;
    for (std::string line; getline(infile, line);)
    {
        if (i == 0)
            { time = stod(std::regex_replace(line, std::regex(R"([^.0-9\\])"), "")); i++; }
        else
            record = stod(std::regex_replace(line, std::regex(R"([^.0-9\\])"), ""));
    }

    /* Quadratic Formula */
    double x_max = (time + std::sqrt(pow(time,2) - (4 * record))) / 2;
    double x_min = (time - std::sqrt(pow(time,2) - (4 * record))) / 2;

    /* Returns upper and lower bounds of Quadratic Equation */
    std::cout << "Upper Bounds: " << x_max << std::endl;
    std::cout << "Lower Bounds: " << x_min << std::endl;

    std::cout << "Sum -> " << (long)(x_max - x_min) << std::endl; // returns '40651270' (correct answer for my data set)

    return 0;
}

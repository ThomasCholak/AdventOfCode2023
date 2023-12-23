#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <numeric>

int main() {
    std::ifstream infile("input.txt");

    std::vector<int> total_nums;  // used for storing total points

    size_t colon_pos;
    size_t bar_pos;  // used to store positions of ':' and '|' in 'line' string

    std::string part1;
    std::string part2;

    std::vector<std::vector<int>> win_Matrix;  // vector matrix to store winning numbers
    std::vector<std::vector<int>> your_Matrix; // vector matrix to store the numbers on your ticket

    for (std::string line; getline(infile, line);)  //reads 'input' file line by line
    {
        colon_pos = line.find(':');           // finds position of "colon" in "line" string
        line.erase(0, colon_pos + 1);    // erases "Game", subsequent game number, and ":"
        bar_pos = line.find('|');            // finds position of "|" character

        // DIVIDES string into two parts using the '|' character
        part1 = line.substr(0, bar_pos);
        part2 = line.substr(bar_pos + 1);

        // CONVERTS string (ex: "1 2 3 4") into an integer vector array
        // https://stackoverflow.com/questions/20659066/parse-string-to-vector-of-int
        std::stringstream iss_1(part1);

        int number_1;
        std::vector<int> win_Num;
        while (iss_1 >> number_1)
            win_Num.push_back(number_1);

        std::stringstream iss_2(part2);

        int number_2;
        std::vector<int> your_Num;
        while (iss_2 >> number_2)
            your_Num.push_back(number_2);

        win_Matrix.push_back({win_Num});  // pushes to 'win_Matrix' vector which stores the 'win_Num' vector
        your_Matrix.push_back({your_Num});
    }

    // COMPARES the elements each row of both matrices (comparison code from below:)
    // https://www.geeksforgeeks.org/how-to-find-common-elements-between-two-vector-using-stl-in-c/
    for (size_t i = 0; i < win_Matrix.size(); ++i)
    {
        std::vector<int> winning_nums;

        // 'row1' refers to first matrix and 'row2' refers to the second matrix
        std::vector<int> row1 = win_Matrix[i];
        std::vector<int> row2 = your_Matrix[i];

        // sorts rows before comparing them
        sort(row1.begin(), row1.end());
        sort(row2.begin(), row2.end());

        std::vector<int> v(row1.size() + row2.size());
        std::vector<int>::iterator it, st;

        it = set_intersection(row1.begin(),
                              row1.end(),
                              row2.begin(),
                              row2.end(),
                              v.begin());

        for (st = v.begin(); st != it; ++st)
            winning_nums.push_back(*st);  // appends winning numbers to 'winning_nums' integer vector

        // y = (1/2) * (2^(winning_nums.size())) or y=(1/2)*2^x
        total_nums.push_back((0.5) * pow(2,(winning_nums.size())));
    }

    auto result = std::reduce(total_nums.begin(), total_nums.end());  // finds sum of 'total_nums' vector

    std::cout << "Sum -> " << result << std::endl; // prints '27059' which is the correct answer for my data set

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>

int main()
{
    std::ifstream infile("input.txt");

    long long int seed_List[20];  // stores seed list ('initialized on first line on input file')

    std::vector<std::list<long long int>> seed_to_soil;

    int i = 0, j = 0;
    for (std::string line; getline(infile, line);) {
        if (i == 0) {
            line.erase(0, 6);  // removes 'game: ' text

            std::stringstream iss(line);
            long long num;
            while (iss >> num && j < 20)
                seed_List[j++] = num;
            i++;
        }
        else if (i > 4 && i < 22) {
            //std::cout << line << std::endl;

            std::istringstream iss(line);  // parses line 'i'
            std::list<long long int> integers;

            long long number;
            while (iss >> number) {
                integers.push_back(number);  // pushes current long long int into 'integers' vector list
            }

            //for (long long k : integers) {
            //    std::cout << k << " ";
            //}

            seed_to_soil.push_back(integers);  // pushes current '3' numeral vector into 'seed_to_soil' matrix

            //break;
            //i++;
        }
        else if (i > 24 && i < 39) {
            //std::cout<<line<<std::endl;
        }
        else {
            i++;
        }
        i++;
    }

    /*std::cout << "\nInitial-Seeds: " << std::endl;
    for (int i = 0; i < 20; ++i) {
        std::cout << seed_List[i] << " ";
    }*/

    //std::cout << "\nSoil-to-Fertilize: " << std::endl;
    for (const auto& integerList : seed_to_soil) {
        for (long long value : integerList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


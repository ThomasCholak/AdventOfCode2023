#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>


std::list<long long int> parse_int(const std::string& line)
{
    std::istringstream iss(line);    // parses line 'i'
    std::list<long long int> integers;

    long long int number;
    while (iss >> number)
    {
        integers.push_back(number);  // pushes current number to 'integers' vector
    }

    return integers;                    // returns list of three integers
}
void find_Map(const std::list<long long int>& row, long long int seed_List[20])
{
    auto it = row.begin();

    long long y  = *it;  // left-most number (destination start)

    std::advance(it, + 1);
    long long x = *it;  // middle number  (range start)

    std::advance(it, + 1);
    long long max = x + (*it - 1);  // right-most number  (used to calculate the max)

    long long diff = y - x;  // calculates the difference

    for (int i = 0; i < 20; ++i) {
        if (seed_List[i] >= x && seed_List[i] <= max)
        {
            seed_List[i] = seed_List[i] + diff;  // if element is found to be in range, apply the difference
        }
    }
}

int main()
{
    std::ifstream infile("input.txt");

    long long int seed_List[20];  // stores seed list ('initialized on first line on input file')

    /* Initialize Matrices */
    std::vector<std::list<long long int>> seed_to_soil;
    std::vector<std::list<long long int>> soil_to_fert;
    std::vector<std::list<long long int>> fert_to_water;
    std::vector<std::list<long long int>> water_to_light;
    std::vector<std::list<long long int>> light_to_temp;
    std::vector<std::list<long long int>> temp_to_humid;
    std::vector<std::list<long long int>> humid_to_loc;

    int i = 0, j = 0;
    for (std::string line; getline(infile, line);)  // reads 'input' file line by line
    {
        if (i == 0)  // grabs initial seed list
        {
            line.erase(0, 6);  // removes "game: " text

            std::stringstream iss(line);
            long long num;
            while (iss >> num && j < 20)
                seed_List[j++] = num;
            i++;
        }
        else if (i > 4 && i < 22)  // grabs lines for 'seed-to-soil' list
        {
            std::list<long long int> integers = parse_int(line);  // parse current line into integer vector list
            seed_to_soil.push_back(integers);                     // pushes current line into 'seed_to_soil' matrix
        }
        else if (i > 24 && i < 39)  // grabs lines for 'soil-to-fertilize' list
        {
            std::list<long long int> integers = parse_int(line);
            soil_to_fert.push_back(integers);
        }
        else if (i > 41 && i < 65)  // 'fertilizer-to-water'
        {
            std::list<long long int> integers = parse_int(line);
            fert_to_water.push_back(integers);
        }
        else if (i > 67 && i < 115)  // 'water-to-light'
        {
            std::list<long long int> integers = parse_int(line);
            water_to_light.push_back(integers);
        }
        else if (i > 117 && i < 145)  // 'light-to-temperature'
        {
            std::list<long long int> integers = parse_int(line);
            light_to_temp.push_back(integers);
        }
        else if (i > 147 && i < 171)  // 'temperature-to-humidity'
        {
            std::list<long long int> integers = parse_int(line);
            temp_to_humid.push_back(integers);
        }
        else if (i > 173 && i <= 232)
        {
            std::list<long long int> integers = parse_int(line);
            humid_to_loc.push_back(integers);
        }
        else
        {
            i++;  // skips current line if a match isn't found
        }
        i++;
    }

    for (const auto& row : seed_to_soil)
    {
        find_Map(row, seed_List);
    }

    std::cout << "Final Seed List: " << std::endl;
    for (long long m : seed_List)
        std::cout << m << " ";
    
    return 0;
}


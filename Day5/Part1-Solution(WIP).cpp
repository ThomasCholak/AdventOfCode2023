#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>

bool findNumberInRanges(int number, const std::vector<std::pair<int, int>>& ranges_vector, size_t& index) {
    for (size_t i = 0; i < ranges_vector.size(); ++i)
    {
        if (number >= ranges_vector[i].first && number <= ranges_vector[i].second)
        {
            index = i; // index num
            return true;
        }
    }
    return false;
}

std::list<long long int> parse_int(const std::string& line)
{
    std::istringstream iss(line);    // parses line 'i'
    std::list<long long int> integers;

    long long int number;
    while (iss >> number)
        integers.push_back(number);  // pushes current number to 'integers' vector

    return integers;                    // returns list of three integers
}

void find_Map(const std::vector<std::list<long long int>>& matrix, long long int seed_List[20])
{
    std::vector<std::pair<long long int, long long int>> x_ranges;
    std::vector<long long int> y_values;

    for (const auto& row : matrix)
    {
        long long y; long long x; long long repeat_num;
        for (long long int value: row)
        {
            auto it = row.begin(); // initializes 'it' as an iterator
            y  = *it;                          // left-most number (destination start)

            std::advance(it, + 1);
            x = *it;                          // middle number  (range start)

            std::advance(it, + 1);
            repeat_num = *it;                 // right-most number  (used to calculate the repeat_num)
        }
        // std::cout << y << " " << x << " " << repeat_num << " " << std::endl;
        x_ranges.emplace_back(x, x + (repeat_num - 1));
        y_values.push_back(y);
    }
    for (const auto& range : x_ranges)
        std::cout << "Start: " << range.first << ", End: " << range.second << std::endl;
    for (long long int value : y_values)
        std::cout << value << " ";
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

    find_Map(seed_to_soil, seed_List);

    int size = sizeof(seed_List) / sizeof(seed_List[0]);
    long long min = seed_List[0];

    /*
    std::cout << "Final Seed List: " << std::endl;
    for (long long m : seed_List)
        std::cout << m << " ";
    */

    for (int k = 1; k < size; ++k)  // function to find the minimum
        if (seed_List[k] < min)
            min = seed_List[k];

    //std::cout << "\nMin: " << min << std::endl;
    return 0;
}

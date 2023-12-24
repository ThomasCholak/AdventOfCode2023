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

    /*
    std::cout << "Seed-to-Soil: " << std::endl;
    for (const auto& integerList : seed_to_soil) {
        for (long long value : integerList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
     */
    /*
    std::cout << "\nSoil-to-Fertilize: " << std::endl;
    for (const auto& integerList : soil_to_fert) {
        for (long long value : integerList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
     */
    /*
    std::cout << "\nFertilizer-to-Water: " << std::endl;
    for (const auto& integerList : fert_to_water) {
        for (long long value : integerList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
     */
    /*
    std::cout << "\nWater-to-Light: " << std::endl;
    for (const auto& integerList : water_to_light) {
        for (long long value : integerList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
     */
    /*
    std::cout << "\nLight-to-Temp: " << std::endl;
    for (const auto& integerList : light_to_temp) {
        for (long long value : integerList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
     */
    /*
    std::cout << "\nTemp-to-Humidity: " << std::endl;
    for (const auto& integerList : temp_to_humid) {
        for (long long value : integerList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
     */
    std::cout << "\nHumidity-to-Location: " << std::endl;
    for (const auto& integerList : humid_to_loc) {
        for (long long value : integerList) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}


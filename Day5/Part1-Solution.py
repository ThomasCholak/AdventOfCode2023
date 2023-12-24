def parse_int(number):
    num_list = list(map(int, number.split()))
    return num_list


if __name__ == "__main__":
    # have to initialize lists for storing mapping data
    seed_List = []
    seed_to_soil = []
    soil_to_fert = []
    fert_to_water = []
    water_to_light = []
    light_to_temperature = []
    temp_to_humid = []
    humid_to_loc = []

    with open('input.txt', 'r+') as file:
        temp = file.read().splitlines()

    for i in range(len(temp)):

        res_1 = temp[0].replace("seeds: ", "")  # removes 'seeds: ' from beginning of string
        seed_List = parse_int(res_1)  # parse first line into integer list
        # print(seedList)

        if 2 < i < 19:
            temp_list = parse_int(temp[i])  # seed-to-soil
            seed_to_soil.append(temp_list)
        elif 20 < i < 34:
            temp_list = parse_int(temp[i])  # soil-to-fertilizer
            soil_to_fert.append(temp_list)
        elif 35 < i < 58:
            temp_list = parse_int(temp[i])  # fertilizer-to-water
            fert_to_water.append(temp_list)
        elif 59 < i < 106:
            temp_list = parse_int(temp[i])  # water-to-light
            water_to_light.append(temp_list)
        elif 107 < i < 134:
            temp_list = parse_int(temp[i])  # light to temperature
            light_to_temperature.append(temp_list)
        elif 135 < i < 158:
            temp_list = parse_int(temp[i])  # temperature to humidity
            temp_to_humid.append(temp_list)
        elif 159 < i <= 207:
            temp_list = parse_int(temp[i])  # humidity to location
            humid_to_loc.append(temp_list)
        else:
            continue

    print(seed_List)
    print(seed_to_soil)
    # print(soil_to_fert)
    # print(fert_to_water)
    # print(water_to_light)
    # print(light_to_temperature)
    # print(temp_to_humid)
    # print(humid_to_loc)

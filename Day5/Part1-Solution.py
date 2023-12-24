def parse_int(number):  # parse integers into a list
    num_list = list(map(int, number.split()))
    return num_list

def create_Key(plant_index):
    xvalues = []
    yvalues = []

    for i in range(len(plant_index)):
        repeat_num = plant_index[i][2]
        range_start = plant_index[i][1]
        dest_start = plant_index[i][0]

        for x in range(repeat_num):
            xvalues.append(range_start + x)
            yvalues.append(dest_start + x)
        else:
            continue

    return xvalues, yvalues

def new_Seeds(seeds, xvalues, yvalues):
    for j in range(len(seeds)):
        valid = seeds[j] in xvalues

        if valid:
            key = xvalues.index(seeds[j])
            seeds[j] = yvalues[key]
        else:
            continue
    return seeds

if __name__ == "__main__":
    # have to initialize lists for storing mapping data
    seed_List = []
    seed_to_soil = []
    soil_to_fert = []
    fert_to_water = []
    water_to_light = []
    light_to_temp = []
    temp_to_humid = []
    humid_to_loc = []

    with open('input.txt', 'r+') as file:
        temp = file.read().splitlines()

    for i in range(len(temp)):

        res_1 = temp[0].replace("seeds: ", "")  # removes 'seeds: ' from beginning of string
        seed_List = parse_int(res_1)  # parse first line into integer list

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
            light_to_temp.append(temp_list)
        elif 135 < i < 158:
            temp_list = parse_int(temp[i])  # temperature to humidity
            temp_to_humid.append(temp_list)
        elif 159 < i <= 207:
            temp_list = parse_int(temp[i])  # humidity to location
            humid_to_loc.append(temp_list)
        else:
            continue

    table_values = [
        seed_to_soil,
        soil_to_fert,
        fert_to_water,
        water_to_light,
        light_to_temp,
        temp_to_humid,
        humid_to_loc
    ]

    for val in table_values:
        x_values, y_values = create_Key(table_values)
        seed_List = new_Seeds(seed_List, x_values, y_values)

    print(seed_List)
    

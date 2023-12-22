import re

if __name__ == "__main__":
    game_total = []  # for storing sums of all values

    with open('input.txt', 'r+') as file:
        temp = file.read().splitlines()

    for i in range(len(temp)):

        tokens = re.split(r'[,:;]', temp[i])

        green_list = []  # initializes list for storing green values
        red_list = []  # stores red values
        blue_list = []  # stores blue values

        for j in range(len(tokens)):

            temp2 = tokens[j].lstrip(' ')  # removes leading whitespace
            res = temp2.split(' ', 1)

            if j == 0:
                continue
            else:
                if res[1] == 'green':
                    green_list.append(int(res[0]))
                elif res[1] == 'red':
                    red_list.append(int(res[0]))
                elif res[1] == 'blue':
                    blue_list.append(int(res[0]))

        game_total.append((max(green_list) * max(red_list) * max(blue_list)))

    print(sum(game_total))  # prints total of 69629 (the correct answer for my data set)

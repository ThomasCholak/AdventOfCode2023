import numpy
import re

if __name__ == "__main__":
    time_list = []
    dist_list = []
    total_list = []

    with open('input.txt', 'r+') as file:
        temp = file.read().splitlines()

        for i in range(len(temp)):  # data for parsing
            result = re.sub('[^.0-9\\s]', '', temp[i])
            res = ' '.join(result.split()).split(' ')
            if i == 0:
                for j in range(len(res)):
                    time_list.append(int(res[j]))  # creates list of integers
            else:
                for j in range(len(res)):
                    dist_list.append(int(res[j]))

    for i in range(len(time_list)):
        temp = 0
        for x in range(time_list[i] + 1):
            d = ((time_list[i] - x) * (0 + x))  # distance = (max_allowed_time - x)(0 + x)
            if d > dist_list[i]:
                temp = temp + 1  # adds one when time beats record
        total_list.append(temp)  # appends 'wins' to a toals list

    print(numpy.prod(total_list))  # 'numpy' method to find the product of a list

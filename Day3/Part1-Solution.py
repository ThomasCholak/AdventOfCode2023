import re


def range_checker(num, start, end):  # returns 'True' if a value in range is found
    return any(start <= numbers <= end for numbers in num)


if __name__ == "__main__":
    with open('input.txt', 'r+') as file:

        matches = []  # stores line_number, numbers and indices for each digit within number
        op_list = []  # stores line_number and indices of operands
        final_sum = []  # lists for appending valid values

        operands = re.compile(r'[=+\-*/&\#@%$]')  # regex to search input file for operands

        temp = file.read().splitlines()

        for i in range(len(temp)):

            for match in re.finditer(r'\d+', temp[i]):
                number = match.group()

                indices = range(match.start() + 1, match.end())
                matches.append((i + 1, int(number), indices))  # stores line_number, full-digit, and ranges of values

            # NOTE: res -> (line_number, instances of operands)
            res = (i + 1, [j.start() + 1 for j in re.finditer(operands, temp[i])])  # looks for indices with operands
            op_list.append(res)

        # function for checking for list matches (finds numbers with operands in range)
        for i in range(len(matches)):

            start_range = matches[i][2].start - 1
            end_range = matches[i][2].stop + 1
            match_num = matches[i][0]

            if matches[i][0] == 1:
                test_res = range_checker(op_list[1][1], start_range, end_range)
                if test_res:
                    final_sum.append(matches[i][1])
            elif matches[i][0] == 140:
                test_res = range_checker(op_list[138][1], start_range, end_range)
                if test_res:
                    final_sum.append(matches[i][1])
            else:

                test_res1 = range_checker(op_list[(match_num - 2)][1], start_range, end_range)
                test_res2 = range_checker(op_list[(match_num - 1)][1], start_range, end_range)
                test_res3 = range_checker(op_list[match_num][1], start_range, end_range)

                test_res4 = any([test_res1, test_res2, test_res3])

                if test_res4:
                    final_sum.append(matches[i][1])

        print(sum(final_sum))

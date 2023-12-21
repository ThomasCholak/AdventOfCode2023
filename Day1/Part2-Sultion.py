# still a work in progress

def concat(int1, int2):
    return int(f"{int1}{int2}")


def reverse_string(x):
    return x[::-1]


if __name__ == '__main__':
    totals = []
    word_list = {'one': "1", 'two': "2", 'three': "3", 'four': "4", 'five': "5", 'six': "6", 'seven': "7",
                 'eight': "8", 'nine': "9"}

    text = open("input.txt", 'r')
    lines = [line.strip() for line in text]

    size = len(lines)

    for i in range(size):
        # matches = [sub for sub in matching_str if sub in str(lines[i])]

        matches = lines[i]
        for word, number in word_list.items():
            matches = matches.replace(word, number)

        result_string = [char for char in matches if char.isdigit()]

        if matches != []:
            b = result_string[0]
            c = result_string[-1]
        else:
            continue

        totals.append(concat(b, c))

    print(sum(totals)) # prints 54926 as a solution
    # print(totals)

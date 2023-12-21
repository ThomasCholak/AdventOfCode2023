
# https://stackoverflow.com/questions/12838549/how-can-i-concatenate-two-integers-in-python
def concat(int1, int2):
    return int(f"{int1}{int2}")


def reverse_string(x):
    return x[::-1]


if __name__ == '__main__':
    totals = []

    text = open("input.txt", 'r')
    lines = [line.strip() for line in text]

    size = len(lines)

    for i in range(size):

        message = str(lines[i])

        for i, a in enumerate(message):
            if a.isdigit():
                b = a
                break

        message = reverse_string(message)

        for i, a in enumerate(message):
            if a.isdigit():
                c = a
                break

        totals.append(concat(b, c))

    print(sum(totals)) # produces answer of 54605

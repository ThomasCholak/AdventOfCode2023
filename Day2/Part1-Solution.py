import re

if __name__ == "__main__":
    with open('input.txt', 'r+') as file:
        temp = file.read().splitlines()

        game_total = []
        maxes = {'blue': 14, 'red': 12, 'green': 13}  # initializes color max dictionary

    for i in range(len(temp)):

        tokens = re.split(r'[,:;]', temp[i])

        valid = True

        for j in range(len(tokens)):

            temp2 = tokens[j].lstrip(' ')  # removes leading whitespace
            res = temp2.split(' ', 1)

            if j == 0:
                game_number = int(res[1])  # stores number of the game
            else:
                if res[1] == 'green':
                    if int(res[0]) > int(maxes['green']):
                        valid = False
                        break
                elif res[1] == 'red':
                    if int(res[0]) > int(maxes['red']):
                        valid = False
                        break
                elif res[1] == 'blue':
                    if int(res[0]) > int(maxes['blue']):
                        valid = False
                        break

        if valid:
            game_total.append(game_number)

    print(sum(game_total))  # produces a solution of 2632 (correct answer)

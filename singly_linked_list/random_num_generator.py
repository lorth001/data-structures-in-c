import random

file = open("random_list.txt", "w")

try:
    for i in range(int(input('How many random numbers?: '))):
        line = str(random.randint(1, 100000000)) + '\n'
        file.write(line)
    print('Done!')
except ValueError:
    # error handling

    file.close()

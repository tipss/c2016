import os


# Show how to use file, read, parse, and print
# and also how to create a csv data
def read_csv(fname):
    file = open(fname, 'r')
    lines = file.readlines()
    file.close()

    lines = [line.strip() for line in lines[1:]]
    for line in lines:
        linex = line.split(' ')
        name = linex[0].title()
        age = linex[1]
        print(f'{name} is of age {age}')


read_csv("./names.txt")
sample_csv_value = ' '.join(['thip','25'])
print(sample_csv_value)
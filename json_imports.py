# Convert json file to dictionary by readin a file
import json

file = open('./friends_json.txt', 'r')
file_contents = json.load(file) #reads file and turns into dictionary
file.close()
print(file_contents['friends'][0])
print(file_contents['friends'][1])

#Convert a dictionary into json file
cars = [{'name':'altima','color':'black'},{'name':'civic','color':'red'}]
fw = open('./cars.txt', 'w')
json.dump(cars, fw)
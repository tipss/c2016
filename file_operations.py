from utils.find import NotFoundError
#part of app.py
def save_to_file(context, filename):
    with open(filename, 'w') as file:
        file.write(content)
def read_file(filename):
    with open(filename, 'r') as file:
        return file.read()
print(__name__)
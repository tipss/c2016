#import utils.common.file_operations

def find_in(iterable, finder, expected):
    for i in iterable:
        if finder(i) == expected:
            return i
        raise NotFoundError(f'{expected} not found in provided iterable')
class NotFoundError(Exception):
    pass

print(__name__)
if __name__ == '__main__':
 print(find_in(['a','b','c'],lambda x: x, 'a'))
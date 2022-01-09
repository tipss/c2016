class Stack:
    def __init__(self):
        self.items = []

    def push(self, e):
        self.items = [e] + self.items  # add to hed
        print (self.items)
    def pop(self):
        head = self.items[0]
        self.items = self.items[1:]
        return head

if __name__ == '__main__':
    s = Stack()
    s.push(10)
    s.push(20)
    print(s.pop())
    print(s.pop())

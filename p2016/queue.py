
class Queue:
    def __init__(self):
        self.items = []
    def push(self, e):
        self.items.append(e) # add to tail
    def pop(self):
        return self.items.pop() # return from head
if __name__ == '__main__':
    q = Queue()
    q.push(10)
    q.push(20)
    print(q.pop())
    print(q.pop())

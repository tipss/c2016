
'''
non recursive
'''
def fib1(n):
    if n <= 1:
        return (n)
    a = 0
    b = 1
    for i in range(n-1):
        a, b = b, a + b
    return b
 
def fib(n):
    if n <=1:
        return n
    return fib(n-1) + fib(n-2)

for i in range(10):
    print(fib(i), " ", fib1(i))

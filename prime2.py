import sys,getopt,os


def primex(in_num) :
    if in_num < 2:
        return
    for num in range(2, in_num) :
        for i in range(2, num):
            if (num % i) == 0:
                break
        else: #Execute tru only if all loop elements are looped without break
            print(num , "is prime")
primex(100)

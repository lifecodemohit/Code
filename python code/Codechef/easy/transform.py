from string import *
def test():
    a = input()
    for i in range(a):
        transform()
def transform():
    var = []
    op = []
    f = ""
    eq = raw_input()
    for i in eq:
        if i== ")":
            x = op.pop()
            f+=x
        elif i.isalpha():
            f+=i
        elif i == "+" or i=="-" or i=="*" or i=="/" or i=="^":
            op.append(i)
    print f
test()
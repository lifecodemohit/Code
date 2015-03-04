def test():
    t = input()
    for i in range(t):
        x = input()
        y = input()
        print race(x, y)
def race(x, y):
    if y>x:
        return y/(y-x)
    else:
        return y/(x-y)
test()
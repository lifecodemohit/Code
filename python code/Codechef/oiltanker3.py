import math
def test():
    t = input()
    for i in range(t):
        z = raw_input()
        z=z.split()
        x = int(z[0])
        y = int(z[1])
        n = x**0.5
        n = int(math.ceil(n))
        a = n**2 - n
        b = n**2 + n
        if y in range(a,b+1):
            print "YES"
        else:
            print "NO"
test()
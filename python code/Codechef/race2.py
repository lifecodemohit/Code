def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a
def lcm(a, b):
    return a * b /gcd(a, b)

def test():
    t = input()
    for i in range(t):
        k = input()
        a = raw_input()
        a = a.split(" ")
        x = 0
        for i in range(k):
            a[i] = int(a[i])
        print reduce(lcm, a)
test()
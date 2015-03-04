#tower of hanoi
def move(src, dest):
    x = src.pop()
    dest.append(x)
def hamoi(n, src, dest, temp):
    if(n==0):
        return

    hanoi(n-1, src, temp, dest)
    move(src, dest)
    print a, c, b
    hanoi(n-1, temp, dest, src)

a = [x for x in range(a)]
b = []
c  =[]
hanoi(4, a, b, c)
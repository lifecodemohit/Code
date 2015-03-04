def Move(src, dest):
     global k
     a = src.pop()
     dest.append(a)
     k-=1
     
def Hanoi(n, src, temp, dest):
    global k
    if n == 0:
        return
    Hanoi(n-1, src, dest, temp)    
    Move(src, dest)
    if k==0 :
        print len(a)
        print len(c)
        print len(b)
    Hanoi(n-1, temp, src, dest)
    
n = input()
k = input()
a = [x for x in range(n)]
b = []
c = []
Hanoi(n, a, c, b)
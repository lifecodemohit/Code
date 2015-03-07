def name(dict, a):
    for i,j in dict.items():
        if j==a:
            return i
def Move(src, dest):
     a = src.pop()
     print "Move", a , "from", name(dict,src), "to", name(dict,dest) 
     dest.append(a)
     
def Hanoi(n, src, dest, temp):
    if n == 0:
        return
    Hanoi(n-1, src, temp, dest)
    
    Move(src, dest)
    print a, c, b
    Hanoi(n-1, temp, dest, src)
    
n = input("Enter number of disks: ")
a = [x for x in range(n)]
b = []
c = []
dict = {"A": a, "B": b, "C": c}
print a, b, c
Hanoi(n, a, c, b)
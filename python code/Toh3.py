def toh(n, )
    global a, b, c, dict
    if n>0:
        toh(n-1)
    
n = input("Enter number of disks: ")
a = [x for x in range(n-1, -1, -1)]
b = []
c = []
print a, b, c
dict = {"A":a, "B":b, "C": c}
toh(n)
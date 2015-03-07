def toh(n, a, b, c):
    if n >0:
        toh(n-1, a, c, b)
        print "move from", a, "to", b
        toh(n-1, c, b, a)
n = input("Enter the number of disks: ")
toh(n,"A", "B", "C" )


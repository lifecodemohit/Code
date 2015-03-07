def hanoi(n, startpos = 1, endpos = 3):
    global a, b, c, dicty
    if n > 0:
        hanoi(n-1, startpos, 6-startpos-endpos)
        dicty[endpos].append(n)
        print "move from peg ", startpos , "to", endpos
        dicty[startpos].pop()
        print a, b,c
        hanoi(n-1, 6-startpos-endpos, endpos)
 
ans = input("Enter number of disks")
a = [ x for x in range(ans, 0, -1) ]
b, c = [], []
print a, b, c
dicty = {1: a, 2: b, 3:c}
hanoi(n = ans)
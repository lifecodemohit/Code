def alpha(n):
    if n==1:
        return "A"
    elif n==2:
        return "B"
    elif n==3:
        return "C"
    else:
        return none
def revsor(lst):
    lst.sort
    z = len(lst)
    lst2 = [0]*z
    for i in range(z):
        lst2[z-i-1] = lst[i]
    return lst2
def hanoi(n, startpos = 1, endpos = 3):
    global a, b, c, dicty
    if n > -1:
        hanoi(n-1, startpos, 6-startpos-endpos)
        dicty[endpos].append(n)
        print "move", n, " from ", alpha(startpos) , "to", alpha(endpos)
        for x in range(len(dicty[startpos])):
            if dicty[startpos][x] == n:
                del dicty[startpos][x]
                break
#        print a, b, c
        print revsor(a), revsor(b),revsor(c)
        hanoi(n-1, 6-startpos-endpos, endpos)
 
ans = input("Enter number of disks")
print "A is the initial peg"
print "C is the final peg"
print "B is the helping peg"
a = [ x for x in range(ans-1, -1, -1) ]
b, c = [], []
print revsor(a), revsor(b), revsor(c)
dicty = {1: a, 2: b, 3:c}
hanoi(ans-1)
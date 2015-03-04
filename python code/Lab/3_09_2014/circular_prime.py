import itertools
def ana(n):
    a = str(n)
    b = a[::-1]
    if int(b)<int(a):
        return 0 
    else:
        return 1
def perm(n):
    #a number
    digits = [int(x) for x in str(n)]
    n = len(digits)
    power = n-1
    a = itertools.permutations(digits)
    l = []
    c =-1
    for i in a:
        c+=1
        l.append([])
        for j in i:
            l[c].append(j)
    return l #2d matrix with permutations of all digits
def joining(lst):
    #lst = 2d list
    n = len(lst) 
    lst2 = [[]]*n
    for i in range(n):
        for j in range(len(lst[i])):
            lst[i][j] = str(lst[i][j])
    for i in range(n):
        lst2[i] = reduce(lambda x, y:x+y, lst[i])
    for i in range(n):
        lst2[i] = int(lst2[i])
    return lst2
    
def prime_num(n):
    for i in range(2, (n/2) +1):
        if n % i == 0:
            return 0
    return 1
def prime_list(lst):
    a = list(set(lst))
    flag = 0
    for i in range(len(a)):
        if prime_num(a[i])!=1:
            return 0
    return 1        
def abc(n):
    z = prime_list(joining(perm(n)))
#    print a,b,c
    if z==1:
        if ana(n)==1:
            final_list.append(n)

final_list = []
global final_list
for i in range(2,1000):
    abc(i)
print final_list
lst = [0,2,3]
l = len(lst)

def prime(n):
    if n==1:
        return 1
    else:
        for i in range(2,n/2 +1):
            if n%i==0:
                return 0
        return 1
def sieve(n):
    for i in range(lst[l-1], n):
        if prime(i)==1:
            lst.append(i)
def check_prime(n):
    if n in lst:
        return 1
    elif n <lst[l-1]:
        return 0
    else:
        sieve(n)
        check_prime(n)
        



def funct(a, b):
    x = check_prime(a)
    y = check_prime(b)
    if((x==0) and (y==0)):
        return a*b
    elif((x==1) and (y==0)):
        a-=1
        return funct(a,b)
    elif((x==0) and (y==1)):
        b-=1
        return funct(a,b)
    elif((x==1) and (y == 1)):
        a-=1
        b-=1
        return funct(a,b)
    else:
        return a*b
t = raw_input()
t = int(t)
for i in range(t):
    a,b = [int(i) for i in raw_input().split(" ")]
    x = funct(a,b)
    print x
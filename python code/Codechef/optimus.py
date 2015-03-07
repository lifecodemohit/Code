def factor(n):
    f = []
    for i in range(1,n+1):
        if n%i==0:
            f.append(i)
    return f
def check_prime(n):
    if n<3:
        return 1
    else:
        for i in range(2, n/2 +1):
            if n%i==0:
                flag = 0
                break
            else:
                flag = 1
        return flag
def flag(j):
    return 5*(4**(j-1))
    
    
n = input()
x = factor(n)
v = len(x)
for i in range(v):
    if check_prime(x[v-i-1])==1:
        j= x[v-i-1]
        break
print flag(j)

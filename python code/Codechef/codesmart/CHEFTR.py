t = raw_input()
t = int(t)
def fact(n):
    if n<=1:
        return 1
    else:
        return n*fact(n-1)
def comb(m, n):
    return fact(m)/(fact(n)* fact(m-n))
 
for i in range(t):
	n,k = [int(i) for i in raw_input().split(" ")]
	x = comb(n,3) - comb(k,3)
	print x
"""
Q1. Make a function to find the nth fibonacci number using the following methods:
    1. Iterative Approach(optional)
    2. Recursive Approach(optional)
    3. [IMP] Using Any of the two Approaches above but using a List.

Example: Input t as the number of times we will input a number 'n'. Calculate this number. 
You will notice that on the way you have calculated something interesting. Can you use this 
something to deal with later queries effectively?
"""
def fibo(n, a=1, b=1):
    if n == 1 or n==0:
        return b
    else:
        return fibo(n-1, b, a+b)

f = []
t = input("Enter t: ")
n = []
for i in range(t):  
    a = input("enter a number: ")
    n.append(a)
    l = len(f)
    if l>0 and a>l:
        for i in range(l, a+1):
            f.append(fibo(i))
        print "fibo: ", f[a]
    elif(l>0 and a<=l):
        print "fibo: ", f[a]
    elif(l==0):
        for i in range(a+1):
            f.append(fibo(i))
        print "fibo: ", f[a]
    
    
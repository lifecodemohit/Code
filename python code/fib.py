"""f(x)= 0, x=1;
         1, x=2;
         f(x-1) + f(x-2), x!=1,2"""

def fib(n):
    if n==1 or n==2:
        return n-1
    return fib(n-1)+fib(n-2)
print fib(input("Enter a number: "))
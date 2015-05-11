import math
primenumber = [2,3]
def isprime(n):
    if n == 2:
        return True
    if n%2 == 0 or n <= 1:
        return False
    sqr = int(math.sqrt(n)) + 1
    for divisor in range(3, sqr, 2):
        if n%divisor == 0:
            return False
    return True

def addprime(n):
	# print n>primenumber[len(primenumber)-1]
	if (n>primenumber[len(primenumber)-1]):
		for i in range(primenumber[len(primenumber)-1]+1, n+1):
			if(isprime(i)==True):
				primenumber.append(i)
				# print "blah blah", i

def primes(n):
    primfac = []
    d = 2
    x = 1
    while n >= d*d:
        while (n % d) == 0:
            if d not in primfac:
                primfac.append(d)
                x*=d
            n //= d
        d += 1
    if n > 1:
       primfac.append(n)
       x*=n
    return x

def primefactors(n):
	primfac = []
	addprime(n)
	for i in primenumber:
		if (i>n):
			break
		else:
			if(n%i==0):
				primfac.append(i)
	# print n, primfac
	return primfac
t = input()
while(t>0):
	t -= 1
	z = raw_input()
	zx = z.split()
	a = int(zx[0])
	b = int(zx[1])
	# print primenumber
	x = primes(b)
	# print "correct", 
	if(a%x==0):
		print "Yes"
	else:
		print "No"
"""
	x = primefactors(b)
	flag = 0

	for i in x:
		# print "lalala", i
		if(b%i==0 and a%i!=0):
			flag = 1
			break
	if (flag==0):
		print "Yes"
	else:
		print "No"
"""	

	
# """
		

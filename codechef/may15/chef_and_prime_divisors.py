from fractions import gcd
t = input()
while(t>0):
	t -= 1
	z = raw_input()
	zx = z.split()
	a = int(zx[0])
	b = int(zx[1])	
	c = gcd(a,b)
	z = b/c
	flag = 0
	while(flag==0):
		if(z==1):
			print "Yes"
			flag = 1
		else:
			c = gcd(a,z)
			if(c==1):
				print "No"
				flag = 1
			z = z/c
from fractions import gcd
t = input()
while(t>0):
	t -= 1
	z = raw_input()
	zx = z.split()
	a = int(zx[0])
	b = int(zx[1])	
	c = gcd(a,b)
	z = b/c
	flag = 0
	while(flag==0):
		if(z==1):
			print "Yes"
			flag = 1
		else:
			c = gcd(a,z)
			if(c==1):
				print "No"
				flag = 1
			z = z/c

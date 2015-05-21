# import math
powersof2 = [1]
mod = 1000000007
t = input()
while(t>0):
	t = t-1
	n = input()
	myset = raw_input()
	myset = myset.split()
	for i in range(len(myset)):
		myset[i] = int(myset[i])
	myset.sort()
	mysum = 0

	for i in range(n-1, 0, -1):
		z = len(powersof2)-1;
		while(z<i):
			z+=1
			y = 2**z
			# y = math.pow(2,z)
			y = y%mod
			powersof2.append(y)

		# mysum+= ((2**i) - 1)*(myset[i] - myset[n-1-i])
		a = (int(powersof2[i]) - 1 + mod)%mod
		b = myset[i]
		c = myset[n-1-i]
		# d = b-c
		d = (b-c+mod)%mod
		e = a*d

		mysum=((mysum%mod)+(e%mod))%mod
	print int(mysum)

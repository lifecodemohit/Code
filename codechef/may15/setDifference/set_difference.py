
# powersof2 = [1]*100000
# flagForPower = [0]*100000
mod = 1000000007

def modExp(b, e):
	x = 1
	for i in xrange(e):
		x = (x*b)%mod
	return x

t = input()
while(t>0):
	t = t-1
	n = input()
	A = []
	for i in range(n):
		A.append((((modExp(2,i))) -(1%mod))%mod)
	myset = raw_input()
	myset = myset.split()
	for i in range(len(myset)):
		myset[i] = int(myset[i])
	myset.sort()
	mysum = 0

	for i in range(n):
		# mysum+= ((2**i) - 1)*(myset[i] - myset[n-1-i])
		# if(flagForPower[i]==0):
			# powersof2[i] =(2**i)%mod
			# flagForPower[i] = 1
		# a = ((powersof2[i]) - 1 + mod)%mod
		# b = myset[i]
		# c = myset[n-1-i]
		# d = b-c
		# d = (b-c+mod)%mod
		# e = a*d
		if(i==0):
			mymax = 0;
			mymin = ((myset[i]%mod) * A[n-1])%mod
		elif(i==n-1):
			mymin = 0
			mymax = ((myset[i]%mod)*A[i])%mod
		else:
			mymin = ((myset[i]%mod)*A[n-i-1])%mod
			mymax = ((myset[i]%mod) * A[i])%mod

		# mysum=((mysum%mod)+(e%mod))%mod
		mysum = (((mysum %mod + mymax %mod)%mod - mymin%mod + mod)%mod)%mod
	# print
	print mysum
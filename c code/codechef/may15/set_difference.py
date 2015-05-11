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
	maxsum = 0
	minsum = 0
	# (2^n-1) -1*s[n-1] + 2^n-2 -1*s(n-2)

	for i in range(n):
		mysum += myset[i]*(2**(i-1)- 2**(n-1))
		# maxsum += 2**(n-1) - i*myset[n-1] + myset**[n-2] - i*myset[n-2]
		print mysum
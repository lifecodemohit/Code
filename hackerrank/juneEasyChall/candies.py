test = input()
while (test>0):
	test = test -1;
	stri = raw_input()
	stri = stri.split()
	N = int(stri[0])
	T = int(stri[1])
	while(T>0 and N>0):
		T = T-1
		# print N,
		if(N%2==0 ):
			x = N/2
			N = N - x
		elif(N%2==1 ):
			x = (N+1)/2
			N = N-x
		# print N,
		if(N//4>0):
			x = N//4
			N = N-x
		# print N
	print N
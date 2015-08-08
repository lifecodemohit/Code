test = int(raw_input())
while(test>0):
	test-=1
	N = int(raw_input())
	mylist = []
	mylist2 = []
	if(N%2==0):  #even number
		for i in range(1, (N/2)+1):
			mylist.append(i)
			if(N-i+1!=i):
				mylist.append(N-i+1)
		# print mylist
		# print len(mylist)
		for i in range(N-1, 0, -2):
			mylist2.append(mylist[i-1])
			mylist2.append(mylist[i])
	else:
		for i in range(1, ((N+1)/2) +1):
			mylist.append(i)
			if(N-i+1!=i):
				mylist.append(N-i+1)
		# print mylist
		# print len(mylist)
		mylist2.append(mylist[N-1])
		for i in range(N-2, 0, -2):
			mylist2.append(mylist[i-1])
			mylist2.append(mylist[i])
	# print mylist2
	for i in mylist2:
		print i,
	print
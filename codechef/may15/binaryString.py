t = input()
while(t>0):
	t-=1
	z = raw_input()
	zx = z.split()
	a = int(zx[0])
	b = int(zx[1])	
	string = raw_input()
	repeat = 1
	counter = 0
	myList = []
	for i in string:
		myList.append(int(i))
	d = myList[0]
	i = 0
	k = 0
	while(i<len(myList)-2):
		while(k<=b and myList[i]!=myList[i+1]):
			i+=1
			d = myList[i+1]
		while(k<=b and myList[i]==myList[i+1]):
			i+=1
			k+=1
		if(k>b and myList[i]==myList[i+1]):
			counter+=1
			if(myList[i]==1):
				myList[i]=0
				k = 1
				i += 1
				d = 0
			else:
				myList[i]=1
				k = 1
				i += 1
				d = 1

	if(k>b and myList[i+1]==d):
		counter+=1
		if(myList[i]==1):
			myList[i]=0
		else:
			myList[i]=1


	result = ''
	for i in myList:
		result += str(i)
	print counter
	print result


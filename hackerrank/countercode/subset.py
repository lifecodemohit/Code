# Q = input()
# myList = []
# while(Q>0):
# 	Q-=1
# 	inp = raw_input().split()
# 	query = inp[0]
# 	myInteger = int(inp[1])
# 	if(query=='add'):
# 		myList.append(myInteger)
# 	elif(query=='del'):
# 		myList.remove(myInteger)
# 	elif(query=='cnt'):
# 		count = 0
# 		for i in range(len(myList)):
# 			if((myInteger & myList[i]) == myList[i]):
# 				count+=1
# 		print count

Q = input()
mydicty = {}
while(Q>0):
	Q-=1
	inp = raw_input().split()
	query = inp[0]
	myInteger = int(inp[1])
	if(query=='add'):
		if myInteger in mydicty:
			mydicty[myInteger]+=1
		else:
			mydicty[myInteger] = 1
	elif(query=='del'):
		if(mydicty[myInteger]==1):
			del mydicty[myInteger]
		else:
			mydicty[myInteger]-=1

	elif(query=='cnt'):
		count = 0
		for key,value in mydicty.items():
			if(value>0):
				if((key&myInteger)==key):
					count+=value
				# myList = []
				# flag = 0
				# a = str("{0:b}".format(key))
				# b = str("{0:b}".format(myInteger))
				# x = len(a)- len(b)
				# print type(a)
				# z = "0"*x + "0"*(-x)
				# print z
				# if(x>0):
				# 	a = z + a
				# else:
				# 	b = z + b
				# print a,b
				# for i in range(len(a)):
				# 	if(a[i]=='1'):
				# 		myList.append(i)
				# for i in myList:
				# 	# if(i<len(b)):
				# 	print i, b[i], b[i]!=1 
				# 	if(b[i]!='1'):
				# 		flag = 1
				# 	break
				# if(flag==0):
				# 	# print a,b
				# 	count+=value
		# print mydicty
		print count

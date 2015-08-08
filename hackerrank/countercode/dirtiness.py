test = input()
while(test>0):
	test-=1
	inp = raw_input()
	inp = inp.split()
	N = int(inp[0])
	M = int(inp[1])
	#even N
	if(N%2==0):
		#odd M i.e. in 1 to N/2
		if(M%2==1):
			N = N/2
			M = (M+1)/2
			index = M%N
			if(index==0):
				index+= N
			degree = M/N
		else: # even M in N/2+1 to N
			N = N/2
			M = (M)/2
			index = M%N
			if(index==0):
				index+= N
			
			index = (2*N) - index +1		
			# print M+1,N
			degree = (M-1)/N
	# odd N
	else:

		# if(M%N==0):
		# 	index = (N+1)/2;
		# 	degree = M/N - 1
		# else:
		# 	level = M/N
		# 	if((level%2==0 and M%2==0) or (level%2==1 and M%2==1)):
		# 		# M lies on right
		# 		degree = level
		# 		a = N*(level) +1
		# 		b = N*(level+1)
		# 		if(M%2==0):
		# 			mydicty = {}
		# 			count = 0
		# 			for i in range(a,b):
		# 				if i%2==0:
		# 					count%=N/2
		# 					count+=1
		# 					if(count==0):
		# 						count = (N+1)/2
		# 					mydicty[i] = N - count +1
		# 			index = mydicty[M]
		# 		else:
		# 			mydicty = {}
		# 			count = 0
		# 			for i in range(a,b):
		# 				if(i%2==1):
		# 					count%=N/2
		# 					count+=1
		# 					if(count==0):
		# 						count = (N+1)/2
		# 					mydicty[i] = N - count +1
		# 			index = mydicty[M]
		# 	elif((level%2==0 and M%2==1) or (level%2==1 and M%2==0)):
		# 		# M lies on left
		# 		degree = level				
		# 		a = N*(level) +1
		# 		b = N*(level+1)
		# 		if(M%2==1):
		# 			mydicty = {}
		# 			count = 0
		# 			for i in range(a,b):
		# 				if i%2==1:
		# 					count%=N/2
		# 					count+=1
		# 					if(count==0):
		# 						count = (N+1)/2
		# 					mydicty[i] = count 
		# 			index = mydicty[M]
		# 		else:
		# 			mydicty = {}
		# 			count = 0
		# 			for i in range(a,b):
		# 				if(i%2==0):
		# 					count%=N/2
		# 					count+=1
		# 					if(count==0):
		# 						count = (N+1)/2
		# 					mydicty[i] = count
		# 			index = mydicty[M]

		if(M%N==0):
			index = (N+1)/2
			degree = M/N -1
		elif(M%2==0):
			level = M/N
			mydicty = {}
			count = 0
			a = N*(level) +1
			b = N*(level+1) +1
			for i in range(a,b):
				if(i%2==0):
					count%=N/2
					count+=1
					if(count ==0):
						count = (N+1)/2
					mydicty[i] = N- count +1
			# print mydicty, M
			index = mydicty[M]
			degree = level
		elif(M%2==1):
			level = M/N
			mydicty = {}
			count = 0
			a = N*(level) +1
			b = N*(level+1) +1
			for i in range(a,b):
				if(i%2==1):
					count%=N/2
					count+=1
					if(count ==0):
						count = (N+1)/2
					mydicty[i] = count
			# print mydicty, M
			index = mydicty[M]
			degree = level


	print index, degree

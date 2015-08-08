N = input()
inp = raw_input()
inp = inp.split()
plants = []

for i in range(N):
	plants.append(int(inp[i]))
days = 0
flag = 1
while(flag and len(plants)>1):
	toRemove = []	
	count = 0
	for i in range(1,len(plants)):
		if(plants[i-1]<plants[i]):
			toRemove.append(i-count)
			count+=1
	if(len(toRemove)>0):
		# removeset = set(toRemove)			
		# plants = [v for i, v in enumerate(plants) if i not in removeset]
		for i in range(len(toRemove)):
			del plants[toRemove[i]]
			# for j in range(i, len(toRemove)):
			# 	toRemove[j] -=1 
		days+=1
	else:
		flag = 0
print days
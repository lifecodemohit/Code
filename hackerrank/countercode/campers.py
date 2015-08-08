inp = raw_input()
inp = inp.split()
N = int(inp[0])
K = int(inp[1])
# mydicty = {}
inp = raw_input()
inp = inp.split()
snipers = []
# for i in range(1, N+1):
# 	mydicty[i] = 0
for i in range(K):
	snipers.append(int(inp[i]))
	# mydicty[int(inp[i])] = 1
snipers.sort()
# snipers = []
# for i in range(1, N+1):
# 	if(mydicty[i]==1):
# 		snipers.append(i)
count = 0
# print snipers
if len(snipers) > 0:
	count = (snipers[0] - 1 )/2 + 1
	# print 1, snipers[0], count
	for i in range(0, len(snipers)):
		if i < len(snipers)-1:
			count += (snipers[i+1] - snipers[i])/2
			# print snipers[i+1],snipers[i], count
		else:
			count += (N - snipers[i])/2	
			# print N, snipers[i], count
print count

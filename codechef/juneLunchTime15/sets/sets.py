xyz = raw_input()
xyz = xyz.split()
n = int(xyz[0])
q = int(xyz[1])
sets = []
for i in range(n):
	sets.append([i+1])
# print sets
while(q>0):
	q-=1
	xyz = raw_input()
	xyz = xyz.split()
	u = "UNION"
	g = "GET"
	if (xyz[0]==u):
		a = sets[int(xyz[1])-1]
		b = sets[int(xyz[2])-1]
		c = []
		# print a,b
		c = a+b

		# for i in range(len(a)):
		# 	c.append(a[i])
		# for i in range(len(b)):
		# 	c.append(b[i])
		sets[int(xyz[1])-1] = []
		sets[int(xyz[2])-1] = []
		sets.append(c)
	elif (xyz[0]==g):
		a = int(xyz[1])-1
		# print sets[a]
		# sets[a].sort()
		b = int(xyz[2])-1
		print sets[a][b]
	# print sets
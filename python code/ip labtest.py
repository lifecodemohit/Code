def f(p,q,r):
	if p=="o" and q=="o": 
        return r
	elif p=="o" and r=="o":
        return q
	elif q=="o" and r=="o": 
        return p
	elif p=="o": 
        return max(q,r)
	elif q=="o":    
        return max(p,r)
	elif r=="o": 
        return max(p,q)
	else:
        return max(p,q,r)
	
	
str1 = raw_input("Enter the first string: ")
str2 = raw_input("Enter the second string: ")
str1 = "  "+str1
str2 = " "+str2
joke = []
for i in range(len(str1)):
	seq = []
	for j in range(len(str2)):
		seq.append(0)
	joke.append(seq)
	
for x in range(len(str1)):
	for y in range(len(str2)):
		if x==0 and y==0: continue
		p = "o"
		q = "o"
		r = "o"
		if x-1>=0:
			if y-1>=0: p = joke[x-1][y-1]
			q = joke[x-1][y]
		if y-1>=0: r = joke[x][y-1]
		if q != "o": q -= 2
		if r != "o": r -= 2
		if p != "o":
			if str1[x] == str2[y]: p+=2
			else: p -= 3
		joke[x][y] = max(0,f(p,q,r))

seq = []		
for i in joke:
	seq.append(max(i))

print "The matrix obtained is :"
for i in joke:
	print i	
print "Best score for Local Sequence Allignment is: "+str(max(seq))
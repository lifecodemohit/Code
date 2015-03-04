#Write a program to print all permutations of 3 digit number. 
count = 0
for a in range(10):
	for b in range(10):
		for c in range(1,10):
			print c*100 + b*10 + a
			count+=1
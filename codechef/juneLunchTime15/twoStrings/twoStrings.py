test = input()
while(test>0):
	test-=1
	s1 = raw_input()
	s2 = raw_input()
	minim = 0
	maxim = 0
	l = len(s1)
	for i in range(l):
		if s1[i]==s2[i]=='?':
			maxim +=1
			# print "x", s1[i], s2[i], minim, maxim
		elif (s1[i]=='?' or s2[i]=='?'):
			maxim +=1
			# print "y", s1[i], s2[i], minim, maxim
		elif s1[i]!=s2[i]:
			minim +=1
			maxim +=1
			# print "z", s1[i], s2[i], minim, maxim

	print minim, maxim
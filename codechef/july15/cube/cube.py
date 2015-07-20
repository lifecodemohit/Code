test = input()
while(test>0):
	test -=1
	xyz = raw_input()
	xyz = xyz.split()
	f = xyz[0]
	b = xyz[1]
	l = xyz[2]
	r = xyz[3]
	t = xyz[4]
	d = xyz[5]
	# print xyz	
	if(f==r==t or f==l==t or b==r==t or b==l==t or f==r==d or f==l==d or r==b==d or l==b==d):
		print "YES"
	else:
		print "NO"
	

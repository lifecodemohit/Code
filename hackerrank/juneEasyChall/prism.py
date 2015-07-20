test = input()
while(test>0):
	test -=1
	stri = raw_input()
	stri = stri.split()
	x = float(stri[0])
	y = float(stri[1])
	z = float(stri[2])
	a = (x-y+z)/2.00;
	b = (x-z+y)/2.00;
	c = (y+z-x)/2.00;
	area = 2*(a*b + b*c + a*c);
	area = float("{0:.2f}".format(area))
	print area
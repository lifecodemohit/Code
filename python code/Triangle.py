x1=int(raw_input("x1:"))
y1=int(raw_input("y1:"))
x2=int(raw_input("x2:"))
y2=int(raw_input("y2:"))
x3=int(raw_input("x3:"))
y3=int(raw_input("y3:"))
print "Triangle"
print "A(%r,%r)" % (x1,y1)
print "B(%r,%r)" % (x2,y2)
print "C(%r,%r)" % (x3,y3)

A= ((y2-y3)**2 + (x3-x2)**2)
B= ((y3-y1)**2 + (x3-x1)**2)

C= ((y2-y1)**2 + (x2-x1)**2)

if (A==B + C or B==A+C or C==A+B)and((A**0.5)<(B**0.5)+(C**0.5) and (C**0.5)<(B**0.5)+(A**0.5) and (B**0.5)<(A**0.5)+(C**0.5)):
	print "Right Angled Triangle"
elif (A**0.5)>=(B**0.5)+(C**0.5) or (C**0.5)>=(B**0.5)+(A**0.5) or (B**0.5)>=(A**0.5)+(C**0.5):
	print "Not a Triangle"
else:
	print "Not A Right Angled Triangle"
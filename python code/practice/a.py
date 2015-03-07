b = []
a = []
r = input("Enter number of rows: ")
w = input("Enter number of columns: ")
for i in range(w):
	a.append(0)
for i in range(r):
	b.append(a)
print b
for i in range(r):
	for j in range(w):
		print "Enter element of row", i, "and column", j, 
		b[i][j] = input()
		print "b", i, j, "=",b[i][j]
	print "b", i,"=", b[i]
print b
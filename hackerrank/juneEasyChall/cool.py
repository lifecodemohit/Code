bin = ""
def binary(num, bin):
	# print bin
	if(num <=1):
		print num
		bin = bin + str(num)
		return
	remainder = num%2
	binary(num >> 1, bin)
	# print remainder
	bin = bin + str(remainder)
	print bin
binary(24, bin)
print "blah " + bin
# bin = ""
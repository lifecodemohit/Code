def fibo(num, a=1, b=1):
	if(num==1):
		return b
	else:
		print num-1, b, a+b
		return fibo(num-1, b, a+b)
print fibo(input("Enter a number:"))
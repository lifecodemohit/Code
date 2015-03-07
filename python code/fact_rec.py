def fact(num, a=1):
	if(num == 1):
		return a
	else:
		return fact(num-1, num*a)

print fact(input("Enter a number to find factorial of: "))
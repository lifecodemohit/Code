#Write a program to print the sum of elements in a list using recursion only
def Sum(a,size):
	if size == 0:
		return 0
	else:
		return a[size-1] + Sum(a,size-1)

n = input("Enter the number of elements: ")
a = raw_input("Enter the numbers separated with spaces:")
a = a.split(" ")
a = list(a)
for i in range(n):
	a[i] = int(a[i])

print Sum(a,n)

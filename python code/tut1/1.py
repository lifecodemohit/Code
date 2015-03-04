#Write a program to count the frequency of every alphabet in a string
import string
a = raw_input("Enter a string:")
a.lower()
d = {}
for i in string.lowercase:
	d[i] = 0
for i in a:
	if(i.isalpha()):
		d[i]+=1
print d
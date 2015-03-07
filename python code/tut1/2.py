#Write a program to count the number of Vowels and consonants in a string
import string
a = raw_input("Enter a string:")
a.lower()
vow = ("a", "e", "i", "o", "u")
cvow = 0
ccon = 0
for i in a:
	if i in vow:
		cvow+=1
	else:
		ccon+=1
		
print "count of vowels", cvow
print "count of consonents", ccon
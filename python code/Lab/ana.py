import string
a = raw_input("Enter a string:")
b = raw_input("Enter other string: ")
a = a.split()
b = b.split()
a.sort()
b.sort()
if a==b:
    print "Yes"
else: 
    print "No"
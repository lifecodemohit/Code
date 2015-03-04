# Leap years occur according to the following formula: a leap year is divisible by four, 
# but not by one hundred, unless it is divisible by four hundred. 
# For example, 1992, 1996, and 2000 are leap years, but 1993 and 1900 are not.
# The next leap year that falls on a century will be 2400.
a = input("Enter the year:")
if(a%4==0):
	print a, "is a leap year"
else:
	print a, "is not a leap year"
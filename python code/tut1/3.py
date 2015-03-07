#Write a program to reverse a string using Recursion only
import string
a = raw_input("Enter a string:")
def rev(s):
    if s == "":
        return s
    else:
        return rev(s[1:]) + s[0]
print rev(a)
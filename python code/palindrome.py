a = raw_input()
b = a.lower().strip(" ")
if b[::-1] ==b:
    print "True"
else:
    print "False"
print len(a)-len(b)    
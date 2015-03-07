from sys import argv 
script, filename = argv
txt = open(filename)
print "Here is text written in file %r" % filename
print txt.read()

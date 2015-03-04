from sys import argv
script, filename = argv
print "we are going to erase the data in in the file %r" % filename
print "If you don't want to remove to data hit ctrl-C"
print "If you want to remove to hit RETURN"
raw_input("?")
print "opening the file.."
#target = open(filename)#
target = open(filename, 'w')

print "truncating the file.."
target.truncate()

print "Now i am going to ask you three lines you want to write in the file"
line1 = raw_input("Line 1:")
line2 = raw_input("Line 2:")
line3 = raw_input("Line 3:")

print"I'm going to now write these lines in the file."
target.write(line1)
target.write("\n")
target.write(line2)
target.write("\n")
target.write(line3)
target.write("\n")

print "and finally we close it"
target.close()
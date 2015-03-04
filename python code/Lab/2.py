a = raw_input("Enter a string: ")
a.lower()

for i in a:
    if a.count(i)==1:
        print i
        break
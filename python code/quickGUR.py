from random import randint

def quicksorter(mylist):
    if len(mylist) <= 1:
        return mylist
    pivot = mylist[randint(0, len(mylist)-1)]
    lesslist = []
    greaterlist = []
    for x in mylist:
        if x < pivot:
            lesslist.append(x)
        if x > pivot:
            greaterlist.append(x)
    return quicksorter(lesslist) + pivot +quicksorter(greaterlist)


a = raw_input()
a = a.split(' ')
for x in range(len(a)):
    a[x] = int(a[x])
print a
print quicksorter(a)
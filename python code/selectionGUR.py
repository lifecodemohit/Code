a = raw_input()
a = a.split(' ')
for x in range(len(a)):
    a[x] = int(a[x])
print a
for x in range(len(a)):
    place = x
    for y in range(x+1, len(a)):
        if (a[y] < a[place]):
            place = y
    a[x], a[place] = a[place], a[x]
            
print a
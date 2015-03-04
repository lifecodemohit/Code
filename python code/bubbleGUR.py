a = raw_input()
a = a.split(' ')
for x in range(len(a)):
    a[x] = int(a[x])
print a
for x in range(len(a)):
    for y in range(x+1, len(a)):
        if (a[y] < a[x]):
            a[x], a[y] = a[y], a[x]
            
print a
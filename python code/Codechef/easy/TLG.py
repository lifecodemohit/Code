t = input()
p1=0
p2=0
for i in range(t):
    a = raw_input()
    a = a.split()
    for i in range(len(a)):
        a[i] = int(a[i])
    if a[0]>a[1]:
        lead = a[0]-a[1]
        if(p1<lead):
            p1 = lead
    else:
        lead = a[1]-a[0]
        if(p2<lead):
            p2 = lead
if(p1>p2):
    print 1, p1
else:
    print 2, p2
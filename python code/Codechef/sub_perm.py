def test():
    t = input()
    while(t):
        ss()
def ss():
    a = raw_input()
    b = raw_input()
    c = {}
    d = {}
    e = []
    for i in b:
        if i in d.keys():
            d[i]+=1
        else:
            d[i] = 1
        if i not in c.keys():
            c[i]=0

    for i in a:
        if i in c.keys():
            c[i]+=1
        else:
            c[i] = 1
    z = 100000
    for i in d.keys():
        if d[i]!=0:
            x = c[i]/d[i]
            if(x < z):
                z = x
        else:
            z = 0
        
    print z
test()
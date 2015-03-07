def test():
    t = input()
    for i in range(t):
        ss()
    
def ss():
    a = [i for i in raw_input()]
    b = [i for i in raw_input()]
    c = [0]*127
    d = [0]*127
    for i in a:
        c[ord(i)] += 1
    for i in b:
        d[ord(i)] += 1
    e = []
    
    for i in range(127):
        if d[i]!=0:
            e.append(c[i]/d[i])
    print min(e)
test()
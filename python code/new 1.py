def add(a,b):
    print a+b
def triangle(a):
    
    c = []
    for i in range(0,a):
        
        b = raw_input().split(' ')
        b = [int(n) for n in b if n.isdigit()]
        
        for x in range(0,len(b)):
            b[x] = int(b[x])
        c.append(b)
        print c
#        c = [[2],[4,3],[3,4,5]]
 #       a(i)
  #      a(i,len(a[]))
        for u in range(0,len(c)):
            for v in range(c[u], len(c[u])):
                add((max(c[u]),max(c[u][v])))
        
    return
a = input("enter the height of triangle")
triangle(a)

f(1) = 2
f(2) = 3
f(3) = 4
f(n) = f(n-1) + f(n-2) + f(n-3)



"""b = [(-1),2,3,4]
for n in range(3, 100001):
    b[n] = b[n-1] +b[n-2] + b[n-3]
    b.append(b[n])

x = b[n-3]
y = b[n-2]
z = b[n-1]
c = [x, y, z]
print len(b)

for n in range(2, 100001):
    c[n] = c[n-1] +c[n-2] + c[n-3]
    c.append(c[n])
    

x = c[n-3]
y = c[n-2]
z = c[n-1]
d = [x, y, z]
print len(c)


for n in range(2, 100001):
    d[n] = d[n-1] +d[n-2] + d[n-3]
    d.append(d[n])
    

x = d[n-3]
y = d[n-2]
z = d[n-1]
print len(d)


for n in range(2, 10000):
    e[n] = e[n-1] +e[n-2] + e[n-3]
    e.append(e[n])
    

x = e[n-3]
y = e[n-2]
z = e[n-1]
f = [x, y, z]
print len(e)

for n in range(2, 10000):
    f[n] = f[n-1] +f[n-2] + f[n-3]
    f.append(f[n])
    

x = f[n-3]
y = f[n-2]
z = f[n-1]
g = [x, y, z]
print len(f)

for n in range(2, 10000):
    g[n] = g[n-1] +g[n-2] + g[n-3]
    g.append(g[n])
    

x = g[n-3]
y = g[n-2]
z = g[n-1]
h = [x,y,z]
print len(g)
for n in range(2, 10000):
    h[n] = h[n-1] +h[n-2] + h[n-3]
    h.append(h[n])
    

x = h[n-3]
y = h[n-2]
z = h[n-1]
i = [x, y, z]

print len(h)
for n in range(2, 10000):
    i[n] = i[n-1] +i[n-2] + i[n-3]
    i.append(i[n])
    

x = i[n-3]
y = i[n-2]
z = i[n-1]
j = [x, y, z]
print len(i)"""
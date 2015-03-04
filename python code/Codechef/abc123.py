"""
def a(n):
    f = open("cypher.txt", "r")
    for i in f:
        i = i.lower()
        z = []
        y = ""
        for j in i:
            if (j!=" "):
                x = ord(j) + n
                if x> 122:
                    x-=26
                y+= str(unichr(x))
            else:
                z.append(y)
                y = ""
    
    return c(z[:-1])
    
    f.close()
def c(lst):
    f = open("wordlist.txt", "r")
    for i in f:
        if i[:-1]==lst[0]:
            return b(lst)
    f.close()
def b(lst):
    word_match = 0
    for i in lst:
        f = open("wordlist.txt", "r")
        for j in f:
            if j[:-1]==i:
                word_match +=1
                break
        f.close()
    if word_match== len(lst):
        return lst
for i in range(26):
    lst = a(i)
    if lst!=None:
        for i in lst:
            print i,
"""
print 0
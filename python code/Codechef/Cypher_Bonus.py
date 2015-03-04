
def a(n):
    f = open("cypher_bonus.txt", "r")
    for i in f:
        i = i.lower()
        z = []
        c_punc = 0
        y = ""
        for j in i:
            
            if ord(j)>122 or ord(j)<97:
                if j == " ":
                    z.append(y)
                    y= ""

                elif j!=" ":
                    z.append(y)
                    z.append(j)
                    
                    y=""
                    c_punc +=1
            else:
                x = ord(j) + n
                if x> 122:
                    x-=26
                y+= str(unichr(x))
    return c(c_punc, z)
    
    f.close()
def c(n, lst):
    x = 0
    for i in range(len(lst)):
        if lst[i].isalpha()==True and len(lst[i])>2:
            x = i
            break
    f = open("wordlist.txt", "r")
    for i in f:
        if i[:-1]==lst[x]:
            print "!!!!"
            return b(n, lst)
def b(n, lst):
    word_match = 0
    for i in lst:
        f = open("wordlist.txt", "r")
        for j in f:
            if j[:-1]==i:
                word_match +=1
                break
        f.close()
    x = lst[0]
    y = lst.count(x)
    
    for i in range(y):
        lst.remove(x)
    if word_match == len(lst)-n:        
        for i in lst:
            print i,
        return
        
        
for i in range(26):
    a(i)
"""
print 0
""" 
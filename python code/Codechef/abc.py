def a(n):
    f = open("cypher_bonus.txt", "r")
    for i in f:
        i = i.lower()
        z = []
        y = ""
        for j in i:
            if ord(j)>122 or ord(j)<97 and j!=" ":
                y+=j
            elif (j!=" "):
                x = ord(j) + n
                if x> 122:
                    x-=26
                y+= str(unichr(x))
            else:
                z.append(y)
                y = ""
    for i in z:
        print i,

a(input())
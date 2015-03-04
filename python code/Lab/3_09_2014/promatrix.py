def inmatrix():
    r1 = input(list)
    r2 = input(list)
    r3 = input(list)
    return [r1, r2, r3]
def pro(m1, m2):
    m = [[0,0,0],[0,0,0],[0,0,0]]
    for x in range(3):
        for y in range(3):
            for i in range(3):
                m[x][y] +=(m1[x][i]) * (m2[i][y])
    return m
a = inmatrix()
b = inmatrix()
#c = [[1,2,3], [4,5,6], [7,8,9]]
#d = [[1,2,3], [4,5,6], [7,8,9]]
print pro(a,b)
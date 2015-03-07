a = raw_input()
b = a.split()
for i in range(len(b)):
    b[i] = int(b[i])
count = 0
for x in range(b[0]):
    
    a = int(raw_input())
    
    if a%b[1]==0:
        count+=1
    else:
        count =count
print count
    
    

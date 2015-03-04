t = raw_input()
t = int(t)
for i in range(t):
    s = raw_input()
    str=''
    n = len(s)
    lst =[0]*26
    for i in s:
        lst[ord(i)-97]+=1
    max = 0
    j=0
    for i in range(26):
        if(lst[i]>max):
            max = lst[i]
            j = i
    j+=97
    c = chr(j)
    for i in s:
        if i==c:
            str+='?'
        else:
            str+=i
    print str
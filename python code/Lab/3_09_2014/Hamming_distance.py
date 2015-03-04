while(1):
    a =raw_input("Please Enter Two strings of same length in the same line seperated with spacaes.")
    a = a.split()
    x = a[0]
    y = a[1]
    if(len(x)==len(y)):break
a = map((lambda i:ord(i)), x)
b = map((lambda i:ord(i)), y)
print a,b
x = 0
for i in range(len(a)):
    x+= a[i]-b[i] 
print x
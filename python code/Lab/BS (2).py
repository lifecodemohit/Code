def bs(lst, x):
    global t
    n= len(lst)
    if(lst[n/2] ==x):
        t = 1
    elif(n==0):
        t = 0
    else:                    
        if(lst[n/2] ==x):
            t = 1
        elif(lst[n/2]>x):
            bs(lst[:n/2],x)
        elif(lst[n/2]<x):
            bs(lst[n/2:],x)
    if t==1:
        print "Yes"
    else:
        print "No"
print "Enter the elements in list in square box: "
#lst = input(list)
lst = [12,45,76,98,21]
lst.sort()
x = input("Enter the element to search:")
t = 0
bs(lst,x)
#quick sort
#randint(1,10) It will choose any integer randomly from 1-10
import random
def quicksort(mylist):
    
    if len(mylist)<=1:
        return mylist
    pivot = mylist[ramdon.randint(0,len(mylist)-1) ]
    lesslist=[]
    greatlist=[]
    for i in mylist:
        if i<pivot:
            lesslist.append(i)
        else:
            greatlist.append(i)
    return quicksort(lesslist)+pivot+quicksort(greatsort)
user_input = input(list)
print quicksort(user_input)
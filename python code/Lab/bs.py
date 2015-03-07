def bs(lst, x):
    n = len(lst)
    if (lst[n-1]<x or lst[0]>x):
        print "No"
    elif(lst[0]==x or lst[n-1]==x):
        print "Yes"
    elif(lst[n/2]>x):
        bs(lst[:n/2], x)
    else:
        bs(lst[n/2:], x)
x = input("Enter the element to search: ")
a = [12,23,43,54,67,87]
bs(a, x)
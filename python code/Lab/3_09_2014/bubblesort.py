#bubble sort
def bubblesort(lst):
    n = len(lst)
    swapped = 1
    while(swapped==1):
        swapped =0
        for i in range(1,n):
            if (lst[i-1]>lst[i]):
                lst[i-1], lst[i] = lst[i], lst[i-1]
                swapped = 1
        n -=1
    return lst
a = [145,203,76,59,11,748]
print a
print bubblesort(a)
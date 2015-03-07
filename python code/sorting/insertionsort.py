def Cplace_left(lst, i):
    v = lst[i]
    j = i
    while(lst[j-1]>v and j>0):
        lst[j] = lst[j-1]
        j-=1
    lst[j] = v
def ins_sort(lst):
    for i in range(1, len(lst)):
        Cplace_left(lst, i)
    return lst

print "Enter a list of elements"
lst = input(list)
print ins_sort(lst)
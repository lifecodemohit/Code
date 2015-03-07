def merge(lsta, lstb):
    lst = []
    while (len(lsta)>0 and len(lstb)>0):
        if(lsta[0]<lstb[0]):
            lst.append(lsta[0])
            lsta.remove(lsta[0])
        elif(lsta[0]>lstb[0]):
            lst.append(lstb[0])
            lstb.remove(lstb[0])
        else:
            lst.append(lsta[0])
            lst.append(lstb[0])
            lsta.remove(lsta[0])
            lstb.remove(lstb[0])
    lst.extend(lsta)
    lst.extend(lstb)
    return lst


def mergesort(lst):
    if(len(lst)<2):
        return lst
    else:
        left = lst[:len(lst)/2]
        right = lst[len(lst)/2:]
        s_left= mergesort(left)
        s_right = mergesort(right)
        return merge(s_left, s_right)

print "Enter a list, example [3,5,1,2]: "
a = input(list)

print mergesort(a)
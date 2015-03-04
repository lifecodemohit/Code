def insertion_sort(mylist):
    for x in range(1, len(mylist)):
        pos = x
        y = x-1
        while (y>=0):
            if (mylist[y]>mylist[x]):
                pos = y
                y = y-1
            else:
                break
        mylist.insert(pos, mylist[x])
       #mylist.insert(position at which number is inserted, number to be inserted)
        del mylist[x+1]
    return mylist
user_input = input(list)
print insertion_sort(user_input)
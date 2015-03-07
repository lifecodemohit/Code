my_lst = raw_input("enter few numbers: ")
my_list = my_lst.split()
for x in range(len(my_list)):
    my_list[x] = int(my_list[x])

for i in range(1,len(my_list)):
    a = my_list[i]
    j = i-1
    while j >=0:
        if a<my_list[j]:
            my_list[j+1]= my_list[j]
            my_list[j]=a
            j = j-1
        else:
            break
print my_list
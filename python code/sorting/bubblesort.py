#bubble sort
def bubblesort(my_list):
    for x in range(len(my_list)):
        for y in range(x, len(my_list)):
            if my_list[y] < my_list[x]:
                my_list[x],my_list[y]=my_list[y], my_list[x]
            
    return my_list
user_input = input(list)
print bubblesort(user_input)

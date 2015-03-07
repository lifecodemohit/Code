t = raw_input();
t = int(t)
for i in range(t):
    n,m = [int(i) for i in raw_input().split(" ")]
    lst = [int(i) for i in raw_input().split(" ")]
    lst = list(lst)
    lst.sort()
    total = 0
    for i in range(n):
        total=total+lst[i]
    sumu =0
    sumb = 0
    if(m>n/2):
        for i in range(m, n):
            sumu +=  lst[i]
        for i in range(m):
            sumb +=  lst[i]
        print sumb -sumu
    else:
        for i in range(m):
            sumb+= lst[i]
        for i in range(m, n):
            sumu+= lst[i]
        print sumu-sumb

def part(list):
    n = len(list)
    p = list[n-1]
    left = []
    right = []
    for i in range(n-1):
        if(list[i]<p):
            left.append(list[i])
        else:
            right.append(list[i])
    return left, p, right
def qsort(list):
    if(len(list)<2):
        return list
    else:
        (left, pivot, right) = part(list)
        return qsort(left)+[pivot]+ qsort(right)
a = [14,42,90,18,-32,54,142]
print qsort(a)
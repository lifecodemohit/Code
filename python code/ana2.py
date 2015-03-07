def fact(a):
    if len(a) > 1:
        l = []
        for i in range(len(a)):
            l += [a[i] + x for x in fact(a[:i] + a[i+1:])]
        return set(l)
    return [a[0]]
from itertools import permutations

def anagramer(gstring):
    a = list(permutations(gstring))
    l = []
    for x in a:
        ans = ''
        for y in x:
            ans = ans + y
        if ans not in l:
            l.append(ans)
    return l
    
take = raw_input()
for x in anagramer(take):
    print x
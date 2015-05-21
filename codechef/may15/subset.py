import itertools
def findsubsets(S,m):
    return set(itertools.combinations(S, m))
a = set([1,2,2,2,3,4,5,6,8])
print
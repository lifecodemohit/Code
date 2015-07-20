from collections import Counter
import math
def get_all_substrings(input_string):
  length = len(input_string)
  return [input_string[i:j+1] for i in xrange(length) for j in xrange(i,length)]

def comb(a, b):
	return math.factorial(a)//(math.factorial(b)*math.factorial(a-b)*1.0)
# print fact(6)
test = input()
while(test>0):
	test -=1
	z = raw_input()
	z = z.split()
	N = int(z[0])
	Q = int(z[1])
	S = raw_input()
	L = get_all_substrings(S)
	G = Counter(L)
	# print G
	count = 0
	for i in range(Q):
		K = input()
		for i in G:
			if (G[i]>K):
				x = comb(G[i], K)
				# print x
				count += x
			elif(G[i]==K):
				# print K
				count+= 1
		# print 
		print count
		count = 0
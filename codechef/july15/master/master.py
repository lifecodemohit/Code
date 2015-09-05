import sys
# print sys.maxint
def knapsack(W, wt, val, n):
	K = [[0. for i in range(W+1)] for j in range(n+1)]
	# print K
	for i in range(n+1):
		for w in range(W+1):
			if(i==0 or w==0):
				K[i][w] = 0
			elif (wt[i-1]<=w):
				K[i][w] = min(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w])
			else:
				K[i][w] = K[i-1][w]
	return K[n][W]
# def knapsack(W, wt, val, n):
# 	if(n==0 or W ==0):
# 		return 0
# 	if(wt[n-1]>W):
# 		return knapsack(W, wt, val, n-1)
# 	else:
# 		return max(val[n-1]+knapsack(W-wt[n-1], wt, val, n-1), knapsack(W, wt, val, n-1))



test = input()
while(test>0):
	test-=1
	xyz = raw_input()
	xyz = xyz.split()
	N = int(xyz[0])
	K = int(xyz[1])
	M = int(xyz[2])
	xyz = raw_input()
	A = []
	mySum = 0
	xyz = xyz.split()
	for i in range(len(xyz)):
		A.append(int(xyz[i]))
	min_cost_to_remove_dish = [201]*N
	for i in range(M):
		xyz = raw_input()
		xyz = xyz.split()
		L = int(xyz[0])-1
		R = int(xyz[1])-1
		C = int(xyz[2])
		for j in range(L, R+1):
			if(C<min_cost_to_remove_dish[j]):
				min_cost_to_remove_dish[j] = C
	# print min_cost_to_remove_dish
	x =  knapsack(K, min_cost_to_remove_dish, A, N)
	print sum(A) - x




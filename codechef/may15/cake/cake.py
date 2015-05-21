# cake.py
mod = 1000000007
test = input()
while(test>0):
	test-=1
	str1 = raw_input()
	str1 = str1.split()
	N = int(str1[0])
	K = int(str1[1])
	Q = int(str1[2])
	A = []
	A.append(0)
	qualityOfDish = []
	qualityOfDish.append(0)
	str1 = raw_input()
	str1 = str1.split()
	a = int(str1[0])
	b = int(str1[1])
	c = int(str1[2])
	d = int(str1[3])
	e = int(str1[4])
	f = int(str1[5])
	r = int(str1[6])
	s = int(str1[7])
	t = int(str1[8])
	m = int(str1[9])
	A.append(int(str1[10]))
	str1 = raw_input()
	str1 = str1.split()
	L1 = int(str1[0])
	La = int(str1[1])
	Lc = int(str1[2])
	Lm = int(str1[3])
	D1 = int(str1[4])
	Da = int(str1[5])
	Dc = int(str1[6])
	Dm = int(str1[7])


	for x in range(2,N+1):
		if((t**x)%s<=r):
			# A[x] = (a*A[x-1]**2 + b*A[x-1] + c) % m
			# u = (a*(A[x-1]**2)) % mod
			uu = a%mod
			uv = (A[x-1]**2) %mod
			u = (uu*uv)%mod
			v = (b*A[x-1]) %mod
			w = c%mod
			A.append((u + v + w) % m)
		else:
			# A[x] = (d*A[x-1]**2 + e*A[x-1] + f) % m
			# u = (d*(A[x-1]**2))%mod
			uu = d%mod
			uv = (A[x-1]**2)%mod
			u = (uu*uv)%mod
			v = (e*A[x-1])%mod
			w = f%mod
			A.append((u+v+w)%mod)
	for i in range(1, Q+1):
		L1 = (((La%Lm) * (L1%Lm))%Lm + (Lc)%Lm) % Lm
		D1 = ((Da%Dm) * (D1%Dm)%Dm + (Dc%Dm)) % Dm
		L = (L1 + 1)%mod
		u = (L+K-1+D1)%mod
		R = min(u, N)
		# print L,R
		x = A[L:R+1]
		# print x
		# print A
		qualityOfDish.append(min(x))
		# print qualityOfDish[i]

	# print qualityOfDish
	print sum(qualityOfDish),
	product = 1
	for i in range(1, len(qualityOfDish)):
		product  *=  qualityOfDish[i]
		product %= mod
	print product
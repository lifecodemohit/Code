t= input()
while (t):
	ans = 0
	nos = input()
	try:
		try:
			nosArr = [int(x) for x in raw_input().split()]
		except:
			pass

		binArr = []
		for x in range (0, 2**nos):
			if (bin(x)[2:].count('1') > 1):
				binArr = [int(x) for x in bin(x)[2:]]
				binArr = [0]*(nos - len(binArr)) + binArr
				# print binArr

				subset = []
				for y in range (0, nos):
					if (binArr[y] == 1):
						subset.append(nosArr[y])
				# print subset
				try:
					ans = ans + (max(subset) - min(subset))

				except:
					pass
	except:
		pass
	print ans%1000000007

	t = t - 1
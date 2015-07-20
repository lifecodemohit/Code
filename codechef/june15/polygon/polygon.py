import operator
# import collections
test = input()
while test>0:
	test-=1
	numberOfPolygons = input()
	posOfPolygons = {}
	for i in range(numberOfPolygons):
		posOfPolygons[i] = i
	for j in range(numberOfPolygons):
		numberOfVert = input()
		arrOfVert = raw_input()
		arrOfVert = arrOfVert.split()
		# print arrOfVert
		maxX = -1000000001
		for i in range(0, len(arrOfVert), 2):
			arrOfVert[i] = int(arrOfVert[i])
			if arrOfVert[i]> maxX:
				maxX = arrOfVert[i]
				# print "maxX", i, maxX
		posOfPolygons[j] = maxX, j
	# print posOfPolygons
	posOfPolygons1 = sorted(posOfPolygons.items(), key=operator.itemgetter(1))
	# print posOfPolygons1
	k = 0
	for i in range(len(posOfPolygons1)):
		posOfPolygons1[i] = list(posOfPolygons1[i])
		posOfPolygons1[i][1] = list(posOfPolygons1[i][1])
		posOfPolygons1[i][1][1] = k
		k+=1 
	# print posOfPolygons1
	myFinalDict = {}
	for i, j in posOfPolygons1:
		myFinalDict[i] = j
	# print myFinalDict
	for i in myFinalDict:
		print myFinalDict[i][1],
	# for i,j in posOfPolygons1:
	# 	print i,j," ", 
	print
import operator
dict = {} # frequency
test = raw_input()
ad = {} #encoded binary
print "enter string : "
for line in test:
	for j in line:
		if j not in ad:
			ad[j] = ""		
		if j in dict:
			dict[j]+=1
		else:
			dict[j]=1
list = sorted(dict.iteritems(), key=operator.itemgetter(1))
def adi():
	global list
	for c in list[0][0]:
		ad[c]="0"+ad[c]
	for c in list[1][0]:
		ad[c]="1"+ad[c]
	str = list[0][0]+list[1][0]
	str_no = list[0][1]+list[1][1]
	list = list[1:]
	list[0]=(str,str_no)
while(len(list)>1):
	adi()
	list=sorted(list,key=operator.itemgetter(1))	
print "Huffman Table :",ad   # THE DICTIONARY OF ALPHABETS
code=""
for i in test:
	code = code + str(ad[i])  # BINARY CODE
print code
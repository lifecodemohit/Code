a = raw_input("enter terms: ")
key = []
value = []

for i in a:
    key.append(i)
    count = 0
    for x in a:
        if x == i:
            count += 1
    value.append(count)
    dictionary = dict(zip(value,key))
print dictionary    

list = []
for key, value in dictionary.iteritems():
    list.append([key, value])
print list

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
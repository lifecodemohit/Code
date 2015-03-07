phrase='hello overflow'
sequence='0101100110011011000101'
tree=[
       [
         [
           [' ', 'f'],
           ['h', 'r']
         ],
         [
           ['w', 'v'],
           'e'
         ]
       ],
       ['l', 'o']
     ]



pos=tree 
for bit in sequence: 
	pos=pos[int(bit)]
	if type(pos).__name__=='str':
		print pos
		pos=tree
from Queue import PriorityQueue

# ENCODER
class Node:
	def __init__(self, left=None, right=None, data=None):
		self.left = left
		self.right = right
		self.data = data

def create_tree(freq):
	p = PriorityQueue()
	for f in freq:
		p.put(f)
	while p.qsize() > 1:
		l, r = p.get(), p.get()
		node = None
		dat = ""
		if isinstance(l[1], Node):
			dat += l[1].data
		else:
			dat += l[1]
		if isinstance(r[1], Node):
			dat += r[1].data
		else:
			dat += r[1]

		node = Node(l, r, dat)
		p.put((l[0] + r[0], node))

	return p.get()

freq = {}
text = raw_input()
for a in text:
	if a in freq:
		freq[a] += 1
	else:
		freq[a] = 1
freq = [(v, k) for k, v in freq.iteritems()]

def walk_tree(root, prefix="", code={}, decode={}):
    if isinstance(root[1], str):
    	code[root[1]] = prefix
    	decode[prefix] = root[1]
    else:
    	walk_tree(root[1].left, prefix + "0", code)
    	walk_tree(root[1].right, prefix + "1", code)
    
    return code, decode

root = create_tree(freq)
codes, decode_table = walk_tree(root)

print "Code Table : ", codes
enc = ""
for a in text:
	enc += codes[a]
print "Encoded text: ", enc

# Decoder
print "Trying to decode: "

decoded = ""
some = ""
for a in enc:
	some += a
	if some in decode_table:
		decoded += decode_table[some]
		some = ""

print decoded
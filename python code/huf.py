from collections import Counter

#####################################################################

class Node(object):
  def __init__(self, pairs, frequency):
    self.pairs = pairs
    self.frequency = frequency

  def __repr__(self):
    return repr(self.pairs) + ", " + repr(self.frequency)

  def merge(self, other):
    total_frequency = self.frequency + other.frequency
    for p in self.pairs:
      p[1] = "1" + p[1]
    for p in other.pairs:
      p[1] = "0" + p[1]
    new_pairs = self.pairs + other.pairs
    return Node(new_pairs, total_frequency)

#####################################################################

def huffman_codes(s):
  frequency_table = Counter(s)
  initial_table = []
  for k, v in frequency_table.items():
    initial_table.append([k, v])
  initial_table = sorted(initial_table, key = lambda p : p[1])
  #print(initial_table)
  table = []
  for entry in initial_table:
    ch = entry[0]
    freq = entry[1]
    table.append(Node([[ch, ""]], freq))
    #print(table)
  while len(table) > 1:
    first_node = table.pop(0)
    second_node = table.pop(0)
    new_node = first_node.merge(second_node)
    table.append(new_node)
    table = sorted(table, key = lambda n : n.frequency)
    #print(table)
  codes = dict(map(lambda p: (p[0], p[1]), table[0].pairs))
  return  codes,"".join([codes[a] for a in s])
#####################################################################

print(huffman_codes('shuchita'))
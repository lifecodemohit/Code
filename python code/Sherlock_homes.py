import operator
fo = open("text.txt", "r")

#NUMBER OF LINES
with open("text.txt", "r") as f:
    flength = len(f.readlines())
print "number of lines:"
print flength

#MOST FREQUENT WORD
my_text =  fo.read()
a = my_text.split()
word_counter = {}
for word in a:
    if word in word_counter:
        word_counter[word]+=1
    else:
        word_counter[word]= 1
print "Word repeating for max number of times:"
print max(word_counter.iteritems(), key=operator.itemgetter(1))[0]
num_words = len(a)
avg_words = num_words/flength
print "avg words per line:"
print avg_words

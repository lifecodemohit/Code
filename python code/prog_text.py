import operator
fo = open("SherlockHolmes.txt", "r")
with open("SherlockHolmes.txt", "r") as f:
    flength = len(f.readlines())
# "number of lines:"
print ""
print "Number of lines: %r" % flength
my_text =  fo.read()
a = my_text.split()
word_counter = {}
for word in a:
    if word in word_counter:
        word_counter[word]+=1
    else:
        word_counter[word]= 1
z =  max(word_counter.iteritems(), key=operator.itemgetter(1))[0]
print ""
print "Word repeating for max number of times: %r" % z
# "avg words per line:"
num_words = len(a)
avg_words = float(num_words)/flength
print ""
print "Avg words per line: %r" %avg_words

count_the = 0
for word in a:
    if word == "Sherlock" or word =="Holmes" or word =="SHERLOCK" or word =="HOLMES":
        count_the+=1

print ""
print "Number of times SHERLOCK or HOMES is repeated: %r" % count_the

# "Longest words:"
longest_word = "the"
for word in a:
    if len(word)>len(longest_word):
        longest_word=word
    elif len(word)== len(longest_word):
        longest_word2 = word
print ""
print "Longest words: " 
print longest_word
print longest_word2
# "avg size per word:"
char_a = 0
for word in a:
    char_a+=len(word)
tchar = char_a

avg_char = float(tchar)/num_words
print ""
print "Avg size per word: %f" % avg_char

"""quotes_l ={}
for word in my_text:
    if word[0] == '"' or word[0] =="'":
        quotes_l.append()
"""




print ""
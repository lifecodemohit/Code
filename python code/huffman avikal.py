words=raw_input('Enter code to be encoded ')
wor= words.lower()
lst=[x for  x in str(wor)] # forms a list of each of the characters
dict={}
for x in lst:
    count=0
    for y in lst:
        if y==x:
            count +=1
            dict[x] = count #the count is the frequency of the letter or whatever we are coding
newdict={}
c=len(dict) # make sure to use this and not len(dict) directly in the if statement as the length is not constant
for i in range(len(dict)):
    v=list(dict.values()) #this will make a list of all the values
    k=list(dict.keys()) #this will make a list of all the keys
    a=k[v.index(max(v))] # this will take the index of the max value in the values list and find its corresponding key
    if i==(c-1) and c!=1: #this takes care of the same character thing
        newdict[a]=str(1)*i #this is done only for the last one which is something like 11111 and doesnt end with 0 as explained by shivam
    else:
        newdict[a]=str(1)*i +str(0)
    del dict[a]
import sys
print "The decoded string is"
for x in wor:
    sys.stdout.write(newdict[x]) # this is used to print without it going to the next line
print " "
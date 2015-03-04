from random import randint
def man(n):
	
	if(n==1):
		print " O"
		print ""
	elif(n==2):
		print " O\n |"
		print ""
	elif(n==3):
		print " O\n\|"
		print ""
	elif(n==4):
		print " O\n\|/"
		print ""
	elif(n==5):
		print " O\n\|/\n |"
		print ""
	elif(n==6):
		print " O\n\\|/\n |\n/"
		print ""
	elif(n==7):
		print " O\n\\|/\n |\n/ \\"
	else:
		print "\t**YOU LOST**\n"
		
def printf(lst):
	for i in range(len(lst)):
		print lst[i],
	print ""
def check_guess(c, guessed):
	flag = 0
	for i in range(len(guessed)):
		if c==guessed[i]:
			flag = 1	
	return flag
	
f = open("words.txt", "r")
a = randint(1,126)
n = 0
while(a>0):
	x = f.readline()
	a-=1
#x = random word from the file.
print "Welcome to Hangman. You got seven chances to guess the word.\n"
x = x.upper()
word = list(x)
word = word[:-1]
#print x
#printf(word)

num = -1

for i in x:
	num+=1
#z = num
#print "number of letters in the word:", num
	
guessed = []
correct = ["_"]*num
printf(correct)

while(n<8):
	a = raw_input("Enter a letter>> ")
	a = a.upper()
	flag= 0
	flag2= 0
	for i in range(len(word)):
		if(a==word[i]):
			correct[i]=a
			if check_guess(a,guessed)==0:
				guessed.append(a)
				
			flag = 1
#	printf(correct)
	if(flag==0):
		for i in range(len(guessed)):
			if(a == guessed[i]):
				print "You have already guessed that number before."
				print ""
				man(n)
				flag2 = 1
		if(flag2==0):
			guessed.append(a)
			n+=1
			print ""
			print "You entered a wrong letter"
			print ""
			man(n)
#			printf(guessed)
	print "Guessed letters",
	printf(guessed)
	print "Progress",
	printf(correct)
	print ""
	if(word==correct):
		print "\t**You win**"
		break
print "The word is",
printf(word)
print ""
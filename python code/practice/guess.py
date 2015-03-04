#The computer will pick a number between 1 and 100. (You can choose any high number you want.) 
#The purpose of the game is to guess the number the computer picked in as few guesses as possible.
from random import randint
a = randint(1,100)
n = 0
b = input("Enter a number from 1 to 100: ")
n+=1
while(1):
	if(b<a):
		b = input("Too low, Enter again: ")
		n+=1
	elif(b>a):
		b = input("Too high, Enter again: ")
		n+=1
	else:
		break
		
print "Congratulations, You got",a, "in", n, "guesses"
print "Temperature Converter"
t = input("Enter the temperature: ")
def FtoC(a):
	return (9/5.0)*(a+32)
def CtoF(a):
	return (5/9.0)*(a-32)

func = input("Convert to Fahrenheit(Enter 1) or Celsius(Enter 2)?")
if (func==1):
	print CtoF(t)
elif(func==2):
	print FtoC(t)

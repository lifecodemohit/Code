import string
print "Loan Calculator"
print ""
amu = input("Amount Borrowed: ")
ir = input("interest rate: ")
t = input("Term (years):")
ip =amu*ir*t/100.0
print "Amount borrowed", amu
print "Interest Paid", ip
print "Pymt# \tAmount Paid\tRemaining Balance"
rem =ip+amu
i = 0
ap = rem/(t*12.0)
while(rem>ip):
	i+=1
	rem-=ap
	print "i\t\t",ap,"\t\t",rem
	
	


sal = input(list)
def giveBonus(sal):
    z = input()
    sal = map(lambda x: x + z, sal)
    return sal
def chargeFine(sal):
    z = input()
    sal = map(lambda x: x-z, sal)
    return sal
while(1):
    print "1. Give bonus\n2. Charge Fine\n3. exit"
    a = input("Enter you choice:")
    if a == 1:
        sal =  giveBonus(sal)
        print sal
    elif(a==2):
        sal =  chargeFine(sal)
        print sal
    else:
        exit()
        

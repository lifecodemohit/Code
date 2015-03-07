def fibo():
    fibit = int(raw_input("Enter fibo number"))
    a = 1
    b = 1
    print a, b, 
    for x in range(fibit-2):
        print a + b,
        b, a = a + b, b

def listel():
    mylist = [ 'horse', 'battery', 'car', 'staple' ]
    print
    for x in range(len(mylist)):
        print x+1, mylist[x]

def sortit():
    lista = [1, 9, 4, 2, 22, -2, 3, 4, 90]
    lista.sort()
    print lista
    
def remit():
    listb = [1, 9, 4, 2, 22, -2, 3, 4, 90]
    for y in range(len(listb)):
        if listb[y] < 5:
            listans = [z for z in listb if listb[y] != z ]
    print listans
            
def freq():
    listc = [ 'apple', 'apple', 'orange', 'orange', 'orange', 'guava', 'guava', 'guava', 'orange', 'guava', 'apple', 'apple', 'apple', 'orange', 'orange' ]
    counter = {}
    for x in listc:
        counter[x] = 0
    for x in listc:
        counter[x] = counter[x] + 1
    print counter

options = { 1: fibo, 2: listel, 3: freq, 4: sortit, 5: remit}
ans = input("Enter choice: \n 1. Fibonacci \n 2. List elements of a list \n 3. Frequency tracker \n 4. Sort a list \n 5. Remove all numbers less than 5 from list \n")
options[ans]()
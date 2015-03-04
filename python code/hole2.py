a = input()
for x in range(a):
    word = raw_input().upper()
    b = list(word)
    count = 0
    for letter in b:
        if letter == "A" or letter == "D" or letter == "O" or letter == "P" or letter == "Q" or letter == "R":
            count+=1
        elif letter == "B":
            count+=2
    print count
    
        
    
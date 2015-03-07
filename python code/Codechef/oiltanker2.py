"""
Naman is taking an oil tanker to his home in peera gadhi. Due to the metro construction he takes a very awkward path to reach his home. Assuming he starts on a coordinate 2D plane at (0,0) facing the positive x-axis. He performs the following steps continuously:
1. move 'k' step fwd.
2. turn left.
3. move 'k' step fwd.
4. turn right.
Now the catch is that the oil tanker is leaking and oil is being spilt along the way. Now we are interested in finding whether oil would be present at some point (x,y) or not.
 
Input

't' the number of test cases. Each test case consists of an integer 'k' and two space seperated integers x and y.
Output

print "YES" if oil would be present at x,y. Print "NO" if not.
Constraints

One step is equivalent to the integer numeric 'one' on the 2-D plane, so 'k' steps are equivalent to the integer 'k'. x and y are positive integers.
Example

Input:
4
4
2 2
5
2 1
1
2 0
7
7 7

Output:
NO
NO
NO
YES
"""
def path(k):
    global m
    m =[[0,0]]
    for i in range(1,k+1):
        m.append([i,0])
    for i in range(1,k+1):
        m.append([k, i])
    for i in range(1,k+1):
        m.append([k+i,k])
    return m
    
    
def test():
    t = input()
    for i in range(t):
        k = input()
        a = raw_input()
        a = a.split()
        for i in range(len(a)):
            a[i] = int(a[i])
        oil(a,k)
def oil(a,k):
    flag = 0
    path(k)
    for i in range(len(m)):
        if(m[i]==a):
            flag = 1
            break
    if(flag==1):
        print "YES"
    else:
        print "NO"

test()      
            

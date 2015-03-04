"""
Manan is taking an oil tanker to his home in peera gadhi. Due to the metro construction 
he takes a very awkward path to reach his home. 
Assuming he starts on a coordinate 2D plane at (0,0) facing the positive x-axis.
 He performs the following steps continuously:
1. move one step fwd.
2. turn left.
3. move one step fwd.
4. turn right.


Now the catch is that the oil tanker is leaking and oil is being spilt along the way. 
Now we are interested in finding whether oil would be present at some point (x,y) or not.
 
Input

't' the number of test cases. Each test case consists of two space seperated integers x and y.
Output

print "YES" if oil would be present at x,y. Print "NO" if not.
Constraints

One step is equivalent to the integer numeric 'one' on the 2-D plane. x and y are positive integers.
Example

Input:
3
2 2
2 1
2 0

Output:
YES
YES
NO
"""
def test():
    t = input()
    for i in range(t):
        a = raw_input()
        a = a.split()
        for i in range(len(a)):
            a[i] = int(a[i])
        oil(a)
def oil(a):
    flag = 0
    if a[0]==a[1]:
        print "YES"
    elif(a[0]-a[1]==1):
        print "YES"
    else:
        print "NO"

test()           

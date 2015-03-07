def g():
    a = input("Number of testcases:")
    def time1():
        T1 = raw_input("Time when Gopal start running(H M S):")
        T2 = raw_input("Time when coach comes(H M S):")
        x = T1.split(' ')
        y = T2.split(' ')
        a = x[0]*3600 + x[1]*60 + x[2]
        b = y[0]*3600 + y[1]*60 + y[2]
        z = (b-a)
        if z[0]%2 = 0:
            print "C"
        else:
            print "S"
        
        
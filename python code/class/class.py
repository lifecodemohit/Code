class Parent(object):
    def altered(self):
        print "This is parent"
class Child(Parent):
    def altered(self):
#        print "Child, Before parent altered"
        super(Child, self).altered()
        print "Child, after altered"
dad = Parent()
son = Child()
#dad.altered()
son.altered()
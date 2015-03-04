class Employee:
    count = 0
    def __init__(self,name, id):
        self.name = name
        self.id = id
        Employee.count = Employee.count+1
    def display_name(self):
        print self.name
    def display_id(self):
        print self.id

e1 = Employee("Jalaj", 2002)
e2 = Employee("Gurshabad", 3001)
e1.display_name()
e2.display_name()
print ("total number of employees", Employee.count)
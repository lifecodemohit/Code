package examples.session3.iiitd;

public class Student{
	String name;
	int rollNumber, batch;
	Branch branch;

	public Student(){
		this.name = "None";
		this.rollNumber = 111;
		this.batch = 2013;
		this.branch = Branch.CSE;
	}

	public Student(String n, int batch,int roll, Branch b){
		this.name = n;
		this.rollNumber = roll;
		this.branch = b;
		this.batch = batch;
	}

	public void printRollNumber(){
		System.out.println(this.rollNumber);
	}
}
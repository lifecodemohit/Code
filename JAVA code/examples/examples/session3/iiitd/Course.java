package examples.session3.iiitd;

public class Course{
	String instructor, name;
	int credits;
	int maxNumberOfStudents;
	Branch branch;

	public Course(String instructor, String name, Branch branch){
		this.instructor = instructor;
		this.name = name;
		this.branch = branch;
		this.credits = 4;
		this.maxNumberOfStudents = 200;
	}

	public Course(String instructor, String name, Branch branch, int credits){
		this.instructor = instructor;
		this.name = name;
		this.branch = branch;
		this.credits = credits;
		this.maxNumberOfStudents = 200;
	}

}
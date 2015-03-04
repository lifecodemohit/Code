package examples.session3.iiitd;

public class University{
	Student[] students;
	Course[] courses;

	public static void main(String[] args) {


		University iiitd = new University();
		iiitd.students = new Student[5];
		iiitd.courses = new Course[5];

		Student student1 = new Student("ABC", 2011, 2011077, Branch.CSE);
		iiitd.students[0] = student1;

		Course ap = new Course("Manish", "Advanced Programming", Branch.CSE);
		iiitd.courses[0] = ap;

		//Print the name of the first course at IIITD.
		System.out.println(iiitd.courses[0].name);

	}
}
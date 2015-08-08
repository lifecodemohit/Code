
public class Employee {
	private String ename;
	private int eno;
	private int esal;
	
	public Employee(String en, int no, int sal){
		ename = en;
		eno = no;
		esal = sal;
	}
	public int getSal(){
		return esal;
	}
	public String getName(){
		return ename;
	}
	public int getNo(){
		return eno;
	}
	public static void main(String[] args){
		
	}

}

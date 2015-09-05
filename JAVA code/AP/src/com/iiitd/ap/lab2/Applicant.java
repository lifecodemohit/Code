//@author Varun Bansal 2013168

package com.iiitd.ap.lab2;

public class Applicant implements Comparable<Applicant>{
	public String name;
	public String id;
	public String program;
	public double CGPA;
	public int prog;
	public String getid(){
		return this.id;
	}
	public Applicant(String name, String id, String program, double cgpa) {
			this.name = name;
			this.id = id;
			this.program = program;
			this.CGPA = cgpa;
			if(program.compareTo("PhD")==0)
				this.prog = 3;
			else if(program.compareTo("PG")==0)
				this.prog = 2;
			else if(program.compareTo("UG")==0)
				this.prog = 1;
			else
				this.prog = 0;

	}
	
	public int compareTo(Applicant other){
		if(this.prog > other.prog)
			return 1;
		else if(this.prog == other.prog){
			if(this.CGPA > other.CGPA)
				return 1;
			else
				return -1;
		}
		else
			return -1;
	}
}

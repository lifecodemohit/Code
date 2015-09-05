//@author Varun Bansal 2013168


package com.iiitd.ap.lab2;

public class InvalidInputException extends Exception{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	public InvalidInputException(){
		super();
		
	}
	public InvalidInputException(String message){
		super(message);
	}
}

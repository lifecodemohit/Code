package exceptionHandling;
import java.io.IOException;
public class Factorial extends IOException
{
	private static final long serialVersionUID = 1L;

	public static int fact(int a) throws MyException{
		if(a<0)
			throw new MyException();
		else if(a==1)
			return 1;
		else
			return a*fact(a-1);
	}

	public static void main(String[] args){
		int n = 12;
		try{
			System.out.println(fact(-5));
			
		}
		catch(MyException e){
			System.out.println("Happy");

			e.printStackTrace();
		}

	}
}	


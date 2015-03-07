import java.util.Scanner;
import java.lang.*;
public class printprime
{
	public static void main(String[] args)
	{
		System.out.println("Enter the integer: ");
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		//PrimeCheck p=new PrimeCheck();
		int result = PrimeCheck.Check(num);
		if (result==0)
			System.out.println("Not prime.");
		else
			System.out.println("prime.");
	}
}
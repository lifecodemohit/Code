import java.util.Scanner;
import java.lang.*;

public class nPrime
{
	public static void main(String[] args)
	{
		int i =0;
		System.out.println("Enter n: ");
		Scanner in =new Scanner(System.in);
		int n = in.nextInt();
		for(i=0; i< n; i++)
		{
			int result = PrimeCheck.Check(i);
			if (result==1)
				System.out.println(i);
		}
	}
}
import java.util.Scanner;
import java.lang.*;

public class Prime
{
//	package Prime;
	public static void main(String[] args)
	{
		System.out.println("Enter the integer: ");
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		int i = 0;
		int prime=1;
		for(i=2; i<num/2 +1; i++)
		{
			if(num%i==0)
			{
				prime =0;
				break;
			}
		}
		if (prime==0)
			System.out.println("Not prime.");
		else
			System.out.println("prime.");
	}
}
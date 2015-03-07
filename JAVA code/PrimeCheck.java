import java.util.Scanner;
import java.lang.*;
public class PrimeCheck
{
	public static int Check(int num)
	{
//		Scanner in = new Scanner(System.in);
//		int num = in.nextInt();
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
		return prime;
	}
}
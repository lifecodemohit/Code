import java.util.Scanner;

public class A2
{
	public static int time()
	{
		int ini=0;
		int count = 0;
		int result = 0;
		int a =0, b=0;
		while(a!=6 && b!=6)
		{
			a = 1+(int)(Math.random()*6);
			b = 1+(int)(Math.random()*6);
			if(a!=6&&b!=6)
				System.out.println(a+" "+ b+" "+ result);
			else
			{
				System.out.println("Game on");
				result = a+b;
				System.out.println(a+" "+ b+" "+ result);
				ini = a+b;
			}
		};
		
		while(result<100)
		{
			a = 1+(int)(Math.random()*6);
			b = 1+(int)(Math.random()*6);
			result = a+b+ini;
			ini = result;
			
			if(a==6 && b==6)
			{
				int c = 0;
				int d = 1+(int)(Math.random()*6);
				if(d==6)
				{
					a = 0;
					b =0;
					d = 0;
					count++;
					System.out.println(count+" "+a+" "+b+" "+result);
					System.out.println("-- "+c+" "+d+" "+result);

				}
			}
			else if(a==6 || b==6)
			{
				int c = 0;
				int d = 1+(int)(Math.random()*6);
				result = d+ini;
				count++;
				System.out.println(count+" "+a+" "+b+" "+result);
				System.out.println("-- "+c+" "+d+" "+result);
			}
			else
			{
				count++;
				System.out.println(count+" "+a+" "+b+" "+result);
			}
		}
		return count;
	}

	
	public static void main(String[] args)
	{
		System.out.println("Enter the number of players: ");
		Scanner in = new Scanner(System.in);
		int p = in.nextInt();
		
		int i = 0;
		int[] arr = new int[p];
		for(i=0; i<p; i++)
		{
			System.out.println("Player "+ i);
			int c = time();
			System.out.println(c);
			arr[i] = c;
		}
		int winner = 0;
		int min = 1000;
		for(i=0; i<p;i++)
		{
			if(arr[i]<min)
			{
				winner = i;
				min = arr[i];
			}
		}
	System.out.println("Winner is Player "+ winner);
	}
}
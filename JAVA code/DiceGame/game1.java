
package DiceGame;
import java.util.*;
import java.lang.*;


public class game1
{
	public static void main(String[] args)
	{
		System.out.println("Enter the number of players: ");
		Scanner in = new Scanner(System.in);
		int p = Integer.parseInt(in.nextLine());
		int i = 0;
		String[] a = new String[p];
		for(i=0; i<p; i++)
		{
			System.out.println("Name of player: "+ i);
			a[i] = in.nextLine();
		}
		for(i=0; i<p; i++)
		{
			System.out.println(i+" "+ a[i]);
			int score = 0;
			while(ini<100)
			{
				player j=new player("mamam");
				ini = j.rollTwoDice();
			}
		}
	}
}
		
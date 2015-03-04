import java.util.*;
public class Game
{
	public static void main(String[] args)
	{
		System.out.println("Enter the number of players: ");
		Scanner in = new Scanner(System.in);
		int p = in.nextInt();
		int i = 0;
		String[] a = new String[10];
		a[0] = in.nextLine();
		for(i=0; i<p; i++)
		{
			System.out.println("Name of player: "+ i);
			a[i] = in.nextLine();
		for(i=0; i<p; i++)
			System.out.println(a[i]);
	}
}
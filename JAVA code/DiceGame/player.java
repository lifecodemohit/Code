package DiceGame;
public class player
{
	String name;
	int score;
	Dice d1, d2;
	public int rollTwoDice()
	{
		Dice d1 = new Dice();
		Dice d2 = new Dice();
		int res1 = d1.roll();
		int res2 = d2.roll();
		score = ini + res1 + res2;
		ini = score;
		System.out.println(res1 +" "+ res2+" "+score);
		if(res1==6||res2==6)
			rollOneDice();
		else
			return ini;
	}
	public int rollOneDice()
	{
		Dice d1 =new Dice();
		Dice d2 =new Dice();
		int res1 = d1.roll();
		int res2 = d2.roll();
		score = ini + res1 + res2;
		System.out.println(res1 +" "+res2+" "+score);
		ini = score;
		return ini;
	}
}
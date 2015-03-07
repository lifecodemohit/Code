public class Player{
	int result = 0;
	int turns = 0;
	int a, b =0;
	while(result<100){
		a = Dice.roll();
		b = Dice.roll();
		result = a+b;
		System.out.println(a+" "+b+" "+result);
		if(a==6||b==6){
			int c = 0;
			int d = Dice.roll();
			result = c+d;
			System.out.println(c+" "+d+" "+result);
		}
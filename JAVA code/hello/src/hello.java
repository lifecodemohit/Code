import java.util.Scanner;
public class hello {
	public hello(){
	}
	
	public int fact(int n){
		if(n<=1){
			return n;
		}
		else{
			return fact(n-1)*n;
		}
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		hello m = new hello();
		int x = in.nextInt();
		System.out.println(m.fact(x));
		System.out.println("Hello World.");
	}

}

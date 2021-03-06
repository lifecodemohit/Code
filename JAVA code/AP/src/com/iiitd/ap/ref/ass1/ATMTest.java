import java.util.Scanner;
public class ATMTest {
	private static Scanner in;
	private static ATM[] ATMMachine;
	private static ATM tempATM;
	private static int flag, menu, inputInt;
	public static void main(String[] args){
		System.out.println("Hello");
		in = new Scanner(System.in);
		ATMMachine = new ATM[5];
		for(int i=0; i<5; i++){
			ATMMachine[i] = new ATM(1000+i, 1000);
		}
		for(int i=0; i<5; i++){
			System.out.println(ATMMachine[i].id);
		}
		flag = 1;
		while (flag == 1){
			menu = 0;
			int i;
			System.out.println("Enter Account id: ");
			int uid = Integer.parseInt(in.nextLine());
			for(i = 0; i<5; i++){
				if(ATMMachine[i].id==uid){
					tempATM = ATMMachine[i];
					menu = 1;
					break;
				}
			}
			
			System.out.println("1. Deposit\t2. Withdraw\t3. Check Balance\t4. Enter another account\t5. Exit");
			while(menu ==1){
				inputInt = Integer.parseInt(in.nextLine());

				if(inputInt==1){
					inputInt = Integer.parseInt(in.nextLine());					
					tempATM.deposit(inputInt);
				}
				else if(inputInt==2){
					inputInt = Integer.parseInt(in.nextLine());
					tempATM.withdraw(inputInt);
				}
				else if(inputInt==3){
					System.out.println(tempATM.checkBal());
				}
				else if(inputInt==4){
					menu = 0;
				}
				else if(inputInt==5){
					menu = 0;
					flag = 0;
				}
				else{
					System.out.print("Enter a valid input: ");
				}
			}
		}
	}
}

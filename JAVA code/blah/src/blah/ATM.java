package blah;
public class ATM {
	int id;
	int balance;
	public ATM(int uid, int depo){
		id = uid;
		balance = depo;
	}
	public void deposit(int n){
		balance+=n;
	}
	public void withdraw(int n){
		if(balance>n)	
			balance -= n;
	}
	public int checkBal(){
		return balance;
	}
}

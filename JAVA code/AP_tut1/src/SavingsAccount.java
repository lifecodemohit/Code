
public class SavingsAccount extends Account{

	public double interest = 10;
	
	public SavingsAccount(int a) {
		super(a);
		// TODO Auto-generated constructor stub
	}
	
	@Override
	
	public void deposit(double sum){
		if (sum>0){
		    setBalance(getBalance()+((interest+100)*sum/100));
		}
		else
		    System.err.println("Account.deposit(...): "+"cannot deposit negative amount.");    
	    
	}
	
}


public class CurrentAccount extends Account{

	public int overdraft = 2000;
	
	public CurrentAccount(int a) {
		super(a);
		// TODO Auto-generated constructor stub
	}
	
	@Override
	public void withdraw(double sum){
		if(sum<0)
			setBalance(getBalance()-sum);
		else if(sum>overdraft)
		    System.err.println("Account.deposit(...): "+"cannot deposit more than "+overdraft);
		else
		    System.err.println("Account.deposit(...): "+"cannot deposit negative amount.");
	}

}
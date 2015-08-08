import java.util.Scanner;;
public class BookTest {
	private static Scanner in;
	private static Book[] books;
	private static int flag;
	private static int inputNum;
	private static String inputStr;
	public static void main(String[] args){
		System.out.println("Max number of books:-");
		in = new Scanner(System.in);
		int n = Integer.parseInt(in.nextLine());
//		int n = 5;
		books = new Book[n];
//		books[0] = new Book("A Tale Of Two Cities", "Charles", 35435, 500, "Fiction");
//		books[1] = new Book("And Then There Were None", "Agatha", 25412, 600, "Fun");
//		books[2] = new Book("Harry Potter", "Rowling", 2015, 450, "Fiction");
//		books[3] = new Book("Master of the Game", "Sydney", 1242, 550, "Thriller");
//		books[4] = new Book("Blah blah blah", "Charles", 14524, 1200, "Fun");
		for(int i=0; i<n; i++){
			System.out.println("Enter details of book " + (i+1) + " apple");
			String bt = in.nextLine();
			String auth = in.nextLine();
			int isbn = Integer.parseInt(in.nextLine());
			int price = Integer.parseInt(in.nextLine());
			String cate = in.nextLine();
			books[i] = new Book(bt, auth, isbn, price, cate);
		}
		flag = 1;
		in = new Scanner(System.in);
//		System.out.println(books[0].authorName.equals("Charles Dickens"));
		System.out.println("1 name of author\t2 category\t3 price\t4 Exit");
		while(flag==1){
			System.out.print("Your choice: ");
			inputNum = Integer.parseInt(in.nextLine());
			if(inputNum == 1){
				inputStr = in.nextLine();
				for(int i=0; i<n; i++){
					if(books[i].authorName.equals(inputStr))
						System.out.println(books[i].bookTitle);
				}
			}
			else if(inputNum==2){
				inputStr = in.nextLine();
				for(int i=0; i<n; i++){
					if(books[i].category.equals(inputStr))
						System.out.println(books[i].bookTitle);
				}
			}
			else if(inputNum==3){
				inputNum = Integer.parseInt(in.nextLine());
				for(int i=0; i<n; i++){
					if(books[i].price <= inputNum)
						System.out.println(books[i].bookTitle);
				}
			}
			else if(inputNum==4)
				flag = 0;
			else
				System.out.println("Enter integer between 1-4");
		}
		
	}
}

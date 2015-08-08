
public class Book {
	String bookTitle;
	String authorName;
	int isbn;
	int price;
	String category;
	
	public Book(String bt, String auth, int isbn_, int pri, String cate){
		bookTitle = bt;
		authorName = auth;
		isbn = isbn_;
		price = pri;
		category = cate;		
	}
	public void setTitle(String bt){
		bookTitle = bt;
	}
	public void setAuthor(String auth){
		authorName = auth;
	}
	public void set_isbn(int isbn_){
		isbn = isbn_;
	}
	public void setPrice(int pri){
		price = pri;
	}
	public void setCate(String cate){
		category = cate;
	}
	public String getTitle(){
		return bookTitle;
	}
	public String getAuthor(){
		return authorName;
	}
	public int get_isbn(){
		return isbn;
	}
	public int getPrice(){
		return price;
	}
	public String getCate(){
		return category;
	}

	
}

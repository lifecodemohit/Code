#include<iostream>
using namespace std;
class Shape{
	protected:
		int width, height;
	public:
		Shape(int a, int b){
			width = a;
			height = b;
		}
		int area(){
			cout << "Parent class area: " <<endl;
			return 0;
		}
};

class Rectangle: public Shape{
	public:
		Rectangle(int a, int b): Shape(a,b){}
		int area()
		{
			cout<< "Rectangle class area: " <<endl;
			return (width*height);
		}
};
class Triangle: public Shape{
	public:
		Triangle(int a, int b): Shape(a,b){}
		int area()
		{
			cout<<"Triangle class area: "<<endl;
			return(width*height/2);
		}
};

int main(){
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle tri(10,5);
	shape = &rec;
	shape->area();
	shape = &tri;
	shape->area();
	return 0;
}
#include<iostream>
using namespace std;
class Type1{
	public:
		int y;
		int z;
		int *x;
};
class Type2{
	int z;
};
int main(){
	cout<<sizeof(Type1)<<endl;
	// cout<<sizeof(Type2)<<endl;
	return 0;
}
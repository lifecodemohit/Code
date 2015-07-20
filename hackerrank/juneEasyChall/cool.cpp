#include <iostream>
using namespace std;
void binary(int number) {
	int remainder;
	if(number <= 1) {
		cout << number;
		return;
	}

	remainder = number%2;
	binary(number >> 1);    
	cout << remainder;
}

int main(){
	binary(24);
	cout << endl;
	return 0;
}
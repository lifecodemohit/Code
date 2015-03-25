#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int main(){

	ofstream myfile;
	myfile.open("tfile1.txt");

	int n = 100000,m = 100000;
	myfile<<n << " " << m << "\n";
	srand(time(NULL));


	while(m--){

		long x = 1 + rand()%n;
		long y = 1 + rand()%n;

		if(x == y){
			m++;
			continue;
		}

		assert( x != y);
		myfile<<x<<" "<< y << "\n";


	}
		
	myfile.close();

	return 0;
	

}

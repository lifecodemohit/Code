#include<stdio.h>
void unsigned1(size_t bytes){
	int bits = 8*bytes;
	unsigned int to = ((1<<(bits-1)-1)+(1<<(bits-1)));
	printf("(0, %u)\n", to);
}
void signed1(size_t bytes){
	int bits = 8*bytes;
	int a = -(1<<(bits-1));
	int b = (1<<(bits-1))-1;
	printf("(%d,%d)\n", a, b);
}
int main(){
	printf("signed char: ");
	unsigned1(sizeof(char));

	printf("unsigned char: ");
	unsigned1(sizeof(unsigned char));

	printf("signed int: ");
	signed1(sizeof(int));

	printf("unsigned int: ");
	unsigned1(sizeof(unsigned int));
 
	printf("signed short int: ");
	signed1(sizeof(short int));

	printf("unsigned short int: ");
	unsigned1(sizeof(unsigned short int));

	printf("signed long int: ");
	signed1(sizeof(long int));

	printf("unsigned long int: ");
	unsigned1(sizeof(unsigned long int));

	printf("float: ");
	signed1(sizeof(float));

	// printf("unsigned long int: ");
	// unsigned1(sizeof(unsigned long int));
	
	return 0;
}
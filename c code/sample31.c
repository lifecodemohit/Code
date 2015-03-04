/*#include<stdio.h>
#include<stdlib.h>

int f(int &x, int c) {
   c  = c - 1;
   if (c == 0) return 1;
   *x = (*x) + 1;
   return f(x, c) * (*x);
} 

int main(void)
{
    int c= 5;
    int x = 5;
    int *ptr = &c;
    int y = f(ptr, c);
    printf("%d", y);
    return 0;
}
*/
#include <stdio.h> 
int f( int&x, c int); 
int main( ) { 
    int num1, num2, *ptr= &num1; 
    num1= 5; 
    num2= f( num1, num1 ); 
    printf( "Answer is %d", num2 ); 
} 
int f( int &x, int c ) { 
    c= c-1; 
    if ( c == 0 ) return 1; 
    x= x+1; 
    return f( x, c ) * x; 
} 

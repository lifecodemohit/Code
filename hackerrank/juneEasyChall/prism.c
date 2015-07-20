#include <stdio.h>
#include <math.h>
int main(){
	int test;
	scanf("%d", &test);
	long double x, y, z, a, b, c, area;
	while(test--){
		scanf("%Lf %Lf %Lf", &x, &y, &z);
		a = (x-y+z)/2.0;
		b = (x-z+y)/2.0;
		c = (y+z-x)/2.0;
		area = 2*(a*b + b*c + a*c);
		area = roundf(area * 100) / 100;
		printf("%Lf\n", area);
	}
	return 0;
}
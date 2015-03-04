#include<stdio.h>
void budget(float c,float a,float bill){
	float pp;
	float tot = c+a;
	float arushi=0, varun=0;
	pp = bill/tot;
	arushi = (a + c/2)*pp;
	varun = (c/2)*pp;
	printf("Bill:%0.2f,	PP:%0.2f,	Arushi:%.2f,	Varun:%.2f\n",bill, pp,arushi, varun);
}
int main(){
	float c, a, bill;
	float arushi, varun;
	c = 18;
	a = 4;
	int i;
	printf("Common friends: %.2f\n", c);
	printf("Arushi's friends: %.2f\n", a);
	for(i=0; i<=10; i++){
		float bill = 8000 +(200*i);
		budget(c,a,bill);
	}
	return 0;
}
		
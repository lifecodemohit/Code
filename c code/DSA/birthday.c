#include<stdio.h>
void budget(int c,int a,int bill){
	int pp;
	int tot = c+a;
	int extra=0;
	int extrapp=0;
	int arushi=0, varun=0;
	int limit=0;
	pp = bill/tot;
	arushi = (a + c/2)*pp;
	varun = (c/2)*pp;
	limit = arushi+varun;
	if(arushi>5000){
		arushi = 5000;
		pp = arushi/(a + c/2);
		varun = (c/2)*pp;
		limit = arushi+varun;
		extra= bill-limit;
		extrapp = extra/(c+a-2);
	}
	printf("Bill:%d	Extra:%d	Treat:%d	PPT:%d	PP:%d\nAru:%d	Var:%d	PPExtra:%d\n",bill,extra,limit,pp,pp+extrapp,arushi, varun, extrapp);
	printf("\n");
}
int main(){
	int c, a, bill;
	int arushi, varun;
	c = 18;
	a = 4;
	int i;
	printf("Common friends: %d\n", c);
	printf("Arushi's friends: %d\n", a);
	for(i=0; i<=10; i++){
		int bill = 8000 +(200*i);
		budget(c,a,bill);
	}
	int q;
	while(1){
		printf("Want to be precise?\n");
		scanf("%d", &q);
		if(q==1){
			printf("Enter the billing amount:");
			scanf("%d", &bill);
			printf("Enter common friends: ");
			scanf("%d", &c);
			printf("Enter Arushi's friends: ");
			scanf("%d", &a);
			budget(c, a, bill);
		}
		else{
			return;
		}
	}
}
		
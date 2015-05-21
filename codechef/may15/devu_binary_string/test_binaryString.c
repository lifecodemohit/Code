#include<stdio.h>
#include<time.h>
int main(){
	FILE *f;
	f = fopen("test.txt", "w");
	int n = 1000;
	fprintf(f, "%d\n", n);
	int i,j;
	int a,b,c;
	for(i=0; i<n; i++){
		a = rand()%1000 + 1;
		b = rand()%a + 1;
		fprintf(f,"%d %d\n", a, b);
		for(j=0; j<a; j++){
			c = rand()%2;
			fprintf(f, "%d", c);
		}
		fprintf(f,"\n");
	}
	fclose(f);
	return 0;
}
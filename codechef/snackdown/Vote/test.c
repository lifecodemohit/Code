#include<stdio.h>
#include<time.h>
int main(){
	FILE *f;
	f = fopen("test.txt", "w");
	int t = 500;
	fprintf(f, "%d ", t);
	int i, j, x;
	for(i=0; i<t; i++){
		int n;
		n = rand()%10 + 1;
		fprintf(f, "%d ", n);
		for(j=0; j<n; j++){
			x = rand()%(n+1);
			fprintf(f, "%d ", x);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return 0;	
}
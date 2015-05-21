#include<stdio.h>
#include<time.h>
int main(){
	FILE *f;
	f = fopen("in.txt", "w");
	int t = 5;
	fprintf(f, "%d\n", t);
	while(t--){
		int n = rand()%1000+1, i;
		fprintf(f, "%d\n", n);
		for(i=0; i<n; i++){
			fprintf(f, "%d ", rand()%1000000000);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return 0;
}
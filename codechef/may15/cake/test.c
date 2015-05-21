#include<stdio.h>
#include<time.h>
int main(){
	FILE *fp;
	fp = fopen("in.txt", "w");
	int test = 1000;
	fprintf(fp, "%d\n", test);
	while(test--){
		int N, K, Q;
		N = rand()%100 + 1;
		Q = rand()%100 + 1;
		K = rand()%N + 1;
		fprintf(fp, "%d %d %d\n", N, K, Q);
		int xyz = 1000;
		int a = rand()%xyz;
		int b = rand()%xyz;
		int c = rand()%xyz;
		int d = rand()%xyz;
		int e = rand()%xyz;
		int f = rand()%xyz;
		int r = rand()%xyz;
		int s = rand()%xyz;
		int t = rand()%xyz;
		int m = rand()%xyz;
		int n = rand()%xyz;
		int Lm = rand()%(N-K+1) +1;
		int Dm = rand()%(K+1) + 1;
		int La = rand()%Lm + 1;
		int Lc = rand()%Lm + 1;
		int Da = rand()%Dm + 1;
		int Dc = rand()%Dm + 1;
		int L1 = rand()%N + 1;
		int D1 = rand()%K + 1;
		fprintf(fp,"%d %d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, r, s, t, m, n);
		fprintf(fp,"%d %d %d %d %d %d %d %d\n", Lm, Dm, La, Lc, Da, Dc, L1, D1);

	}
	fclose(fp);
	return 0;


}
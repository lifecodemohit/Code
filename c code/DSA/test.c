#include<stdio.h>
#include<ctype.h>
void main(){
	int n=2, m=5, i,j;
	char data[n][m];
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			scanf("%c", &data[i][j]);
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			printf("%s", &data[i][j]);
		}
		printf("\n");
	}

}
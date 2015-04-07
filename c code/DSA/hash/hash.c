#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
	FILE *fp;
	int MAX = 5000;
	int p = 10007;
	float A = 3.1453;
	if((fp=fopen("data.txt","r"))==NULL){
		printf("Unable to read file\n");
		exit(1);
	}
	int arr[10000];
	char str[100];
	char i;
	int n, j;
	int h = 0;
	int y;
	float blah;
	int collisions = 0;
	int index;
	for(j=0; j<10000; j++){
		arr[j] = 0;
	}
	while(MAX>0){
		fscanf(fp, "%s", str);
		i = *(str);
		n = strlen(str);
		for(j=0; j<n; j++){
			// printf("%d ", i);
			y = (int)pow(p,j);
			y*=(int)i;
			h+=y;
			i = *(str + j +1);
		}
		// printf("%d\n", h);
		blah = h*A;
		index = (h)%10000;
		// printf("%d\n", h%10000);
		// printf("%d\n", index);
		if(arr[index]==0)
		 	arr[index]= 1;
		else
			collisions++;
		h=0;
		// printf("%s %d\n", str, total);
		MAX--;
	}
	printf("%d\n", collisions);
	fclose(fp);
	return 0;
}
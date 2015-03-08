#include<stdio.h>
#include<stdlib.h>
struct node{
	char name[100];
	int roll;
};
void main(){
	FILE *fp;
	int d, i=0;
	char ch[100];
	struct node hah[5];
	fp = fopen("numbers.txt", "r");
	fscanf(fp, "%s %d", hah[i].name, &hah[i].roll);
	while(i==3){
		getchar();
		i++;
		fscanf(fp, "%s %d", hah[i].name, &hah[i].roll);
	}
	fclose(fp);
	printf("%s\n", hah[0].name);
}	
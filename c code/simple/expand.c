#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void expand(char *myStr){
	int i, n = strlen(myStr);
	for(i=0; i<n; i++){
		if(myStr[i]=='-'){
			int c = myStr[i-1];
			while(c<=myStr[i+1]){
				printf("%c", c);
				c++;
			}
		}
	}
	printf("\n");
}
int main(){
	char *myStr = "1-5c-f";
// try for 1-6, c-g, 1-6c-f, c-f1-6,all will work
// did not understand what the second parameter is for!
	expand(myStr);
	return 0;
}
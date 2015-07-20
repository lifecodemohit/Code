#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void squeeze(char s1[], char s2[]){
	int x;
	int i, j, k, n = strlen(s1), m = strlen(s2), flag = 0;
	for(x=0; x<m; x++){	
		char ch;
		for(i=0; i< n; i++){
			ch = s1[i];
			// printf("%c\n", ch);
			for(j=0; j<m; j++){
				if(ch==s2[j]){
					flag = 1;
					break;
				}
			}
			// s1[i] = 'z';
			if(flag==1){
				if(i==n){
					s1[i] = '\0';
				}
				else{
					for(k=i; k<n; k++){
						s1[k] = s1[k+1]; 
					}
				}
				flag = 0;
			}		
		}
	}
}

int main(){
	char s1[] = "abcdefghijkl";
	char s2[] = "abcd";
	int i = 0, n = strlen(s2); 
	// for(i=0; i<n; i++)
	squeeze(s1, s2);
	printf("%s\n", s1);
	return 0;
}
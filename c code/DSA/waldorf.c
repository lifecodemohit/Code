//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=951
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int flag;
char data[50][50];
int i,j,m,n;
void searchAgain(int xo,int yo, int px, int py, int ax,int ay, int k, char word[]){
	if(k == strlen(word)) {
		printf("%d %d\n",xo,yo);
		flag = 1;
		return;
	}
	if(data[xo+ax][yo+ay] != word[k]) 
		return;
	searchAgain(xo,yo,px,py,ax+px,ay+py,k+1, word);
}
int search(char word[100]){
	int x,y;
	for(x = 1; x <= m; x++){
		for(y = 1; y <= n; y++){
			if(data[x][y] == word[0]){
				searchAgain(x,y,0,1,0,1,1,word); // r
				if(!flag) 
					searchAgain(x,y,-1,0,-1,0,1,word);// up
				if(!flag) 
					searchAgain(x,y,1,1,1,1,1,word); // r-down
				if(!flag) 
					searchAgain(x,y,-1,1,-1,1,1,word); // r-up
				if(flag!=0) 
					searchAgain(x,y,1,0,1,0,1,word); // d
				if(!flag) 
					searchAgain(x,y,0,-1,0,-1,1,word);// l
				if(!flag) 
					searchAgain(x,y,1,-1,1,-1,1,word); // left down
				if(!flag) 
					searchAgain(x,y,-1,-1,-1,-1,1,word); // left up
				if(flag) 
					return;
			}
		}
	}
}
int main(){
	int t;//number of test cases
	scanf("%d", &t);
	while(t>0){
		t--;
		scanf("%d %d", &m, &n);
		for(i = 0; i < m+2; i++)
			data[i][0] = '-';
        for(j = 0; j < n+2; j++)
        	data[0][j] = data[m+1][j] = '.';
        for(i = 1; i <= m; i++) 
        	scanf("%s", data[i]+1);
        for(i = 0; i < m+2; i++) 
        	data[i][n+1] = '.';
        for(i = 1; i <= m+2; i++){
            for(j = 1; j <= n+2; j++)
            	data[i][j]  = tolower(data[i][j]);
            
        }
		int numOfWords;
		scanf("%d", &numOfWords);
		char word[100];
		while(numOfWords>0){
			numOfWords--;
			scanf("%s", word);
			flag = 0;
			int len = strlen(word);
			for(i=0; word[i]!='\0'; i++){
				word[i] = tolower(word[i]);
			}

			search(word);
		}
		if(t>2)
			printf("\n");
	}
	return 0;
}
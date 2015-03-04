#include<stdio.h>
#include<stdio.h>
struct wordlist {
 char* word; 
 struct worldlist* next; 
}  
struct wordlist* hash_table[1000000]

void inithashtab(){
  int i;
  for(i=0;i<HASHSIZE;i++)
    hashtab[i]=NULL;
}

int HashCodeMap(char* word){
    int i;
    int len = strlen(word);
    for(i=0; i<len; i++)
    {
        
    }
}
int CompressionMap (int key){

}

void Insert ()
{
    if()

}
void Search (char* word){

}

int main()
{
    int choice;
    while(1)
    {
        printf("1.Insert\n2.Search>>");
        scanf("%d", &choice);
        if(choide==1)
            Insert();
        else if(choice==2)
            Search();
        else if(choice==3)
            exit(0);
        else
            printf("Invalid choice\n");

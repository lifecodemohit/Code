#include<stdio.h>
#include<stdlib.h>
struct tree{
    int data;
    struct tree *left, *right;
};
struct tree bin_tree;
void insert(struct bin_tree **node, int val){    
    if(*node == NULL){
        *node = (struct tree*)malloc(sizeof(struct tree));
        (*node)->data = val;
        (*node)->left = 0;
        (*node)->right = 0;
    }
    if(val < ())
}
void search(){
}
void destroy(){
}
int main(){
    struct tree *root;
    int val;
    root = NULL;
    while(1){
        printf("1.insert\n2. search\n3. destroy\n4. exit\n");
        int c;
        scanf("%d", &c);
        switch case(c){
            case 1:
                printf("Enter a vaule: ");
                scanf("%d", &val);
                insert(&root);
                break;
            case 2:
                printf("Enter a vaule: ");
                scanf("%d", &val);
                search(&root);
                break:
            case 3:
                destroy(&root);
                break;
            case 4:
                return;
                break;
        }
    }
    return 0;
}
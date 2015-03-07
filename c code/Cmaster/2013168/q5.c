#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{

    FILE *file;
    file = fopen("result.txt", "w");
    int arg1 = atoi(a[1]);
    int arg2 = atoi(a[2]);
    if(argv[3]=="+")
        fprintf(file, "%d\n", arg1 + arg2);
    else if(argv[3]=="-")
        fprintf(file, "%d\n", arg1 - arg2);
    else if(argv[3]=="*")
        fprintf(file, "%d\n", arg1 * arg2);
    else if(argv[3]=="/")
        fprintf(file, "%d\n", arg1 / arg2);
    else
        printf("You did not give any appropriate operator.\n");
    fclose(file);
    while(1)
    {
        char* q[10];
        printf("Yes to Continue, No to exit: ");
        scanf("%s",&q);
        strlwr(q);
        char a;
        if(q=="yes")
        {
            scanf("%d %d %c", &arg1, &arg2, &a);
            FILE *file;
            fopen("result.txt", "a");
            if(a[3]=="+")
                fprintf(file, "%d\n", arg1 + arg2);
            else if(a[3]=="-")
                fprintf(file, "%d\n", arg1 - arg2);
            else if(a[3]=="*")
                fprintf(file, "%d\n", arg1 * arg2);
            else if(a[3]=="/")
                fprintf(file, "%d\n", arg1 / arg2);
            else
                printf("You did not give any appropriate operator.\n");
            fclose(file);
        }
        else
            break;
    }

    return 0;
}

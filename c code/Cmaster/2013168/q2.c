#include<stdio.h>
int print(char c)
{
    putchar(c);
}
int skip(char c)
{
    return;
}
int main(int argc, char* args[])
{
    int c;
    char* word;
    FILE *file;
    int n =0;
    char a;
    file = fopen("abc.txt", "r");
    if (file) {
        while ((c = getc(file)) != EOF)
        {
            while(c!='\0')
            {
                word+=c;
                n++:
            }

        }

        fclose(file);
    }
    else
        printf("File could not be opened.\n");
    return 0;
}

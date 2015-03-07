#include<stdio.h>
int main()
{
    int c;
    FILE *file;
    file = fopen("q1.c", "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    else
        printf("File coud not be opened.\n");

    return 0;
}

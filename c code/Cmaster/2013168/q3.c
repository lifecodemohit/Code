#include<stdio.h>
int main()
{
    int c;
    int count = 2;
    FILE *file;
    file = fopen("q1.c", "r");
    if (file) {
        printf("1 ");
        while ((c = getc(file)) != EOF)
        {
            if(c=='\n')
            {
                printf("\n%i ", count);
                count++;
            }
            else
                putchar(c);

        }
        fclose(file);
    }
    return 0;
}

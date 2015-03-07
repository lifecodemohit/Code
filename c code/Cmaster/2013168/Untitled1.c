#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char* argv[])
{

    FILE *file;
    file = fopen("abc.txt", "w");
    int c;
    FILE *file2;
    file2 = fopen("q1.c", "r");
    if (file) {
        while ((c = getc(file2)) != EOF)
            fprintf(file, "%c", c);
        fclose(file);
    }
    fclose(file2);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_SIZE 10000

struct wordlist
{
    char* word;
    struct worldlist* next;
};

struct wordlist* hash_table[MAX_SIZE];

int CompressionMap(int key)
{
     int a = 1;
     int b = -95;
     int h = (a*key + b)%MAX_SIZE;
     return h;
}

int HashCodeMap(char* word)
{
    int n = strlen(word);
    int i, ans=0;
    for(i=n;i>=0;i++)
    {
        ans += ((int)(word[i]))*pow(10, (n-i));
    }
    return CompressionMap(ans);
}

void Insert (char* wsearch)
{
    struct wordlist *temp = hash_table[HashCodeMap(wsearch)];
    while (temp->next != NULL)
    {
        if (temp->word == wsearch)
        {
            printf("Word already exists.");
            return;
        }
        temp = temp->next;
    }
    if (temp->word == wsearch)
    {
        printf("Word already exists.");
        return;
    }
    struct wordlist *temp2 = (struct wordlist*)(malloc(sizeof(struct wordlist)));
    temp2->word = wsearch;
    temp2->next = NULL;
    temp->next = temp2;
}

void search(char* wsearch)
{
    int address = HashCodeMap(wsearch);
    struct wordlist *temp = hash_table[address];
    int i = 0;
    while (temp->next != NULL)
    {
        if (temp->word == wsearch)
        {
            printf("Word found at position %d, %d", address, i);
            return;
        }
        temp = temp->next;
        i = i+1;
    }
    if (temp->word == wsearch)
    {
        printf("Word already exists.");
        return;
    }
    printf("Word not found");
}

int main()
{
    printf("%d", HashCodeMap("cat"));
    return 0;
}

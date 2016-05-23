#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICT_LEN 178691 // scrabble dictionary
//#define DICT_LEN 354986 // words.txt
#define MAX_WORD_LEN 30

void removeNewline(char* buffer);
int checkWord(char* word, char* dictionary[]);
int checkCircular(char* word, char* dictionary[]);

int main(void)
{
    char* dictionary[DICT_LEN];
    char buffer[MAX_WORD_LEN + 1];
    FILE* fptr = fopen("dictionary.txt", "r");
    if (fptr == NULL)
    {
        printf("Error: unable to open file.\n");
        exit(0);
    }
    for(int i = 0; i < DICT_LEN; i++)
    {
        fgets(buffer, MAX_WORD_LEN, fptr);
        removeNewline(buffer);
        dictionary[i] = malloc( sizeof(char) * ( strlen(buffer) + 1) );
        strcpy(dictionary[i], buffer);
    }
    for(int i = 0; i < DICT_LEN; i++)
    {
        if (checkCircular(dictionary[i], dictionary))
        {
            printf("%s\n", dictionary[i]);
        }
    }
    checkCircular("SPA", dictionary);
    return 0;
}

void removeNewline(char* buffer)
{
    int len = strlen(buffer);
    if (buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';
    }
}

void shiftWord(char* word)
{
    char firstChar = word[0];
    int i, len = strlen(word);
    for (i = 0; i < len - 1; i++)
    {
        word[i] = word[i+1];
    }
    word[i] = firstChar;
}

int checkWord(char* word, char* dictionary[])
{
    int min = 0;
    int max = DICT_LEN - 1;
    int middle;
    while(min <= max)
    {
        middle = (min + max)/2;
        if (strcmp(word, dictionary[middle]) < 0)
        {
            max = middle - 1;
        }
        else if (strcmp(word, dictionary[middle]) > 0)
        {
            min = middle + 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int checkCircular(char* word, char* dictionary[])
{
    char* buffer = malloc(sizeof(char)*(strlen(word)+1));
    strcpy(buffer, word);
    for(int i = 0, len = strlen(word); i < len; i++)
    {
        if (!checkWord(buffer, dictionary))
        {
            return 0;
        }
        shiftWord(buffer);
    }
    return 1;
}

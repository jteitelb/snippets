#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIGITS 10
#define MAX_VALS_PER_DIGIT 4

void decode(int numRemaining, int* remaining, char* previous)
{
    char* tmp;
    char possible[MAX_VALS_PER_DIGIT + 1];
    if (numRemaining == 0)
    {
        printf("%s\n", previous);
    }
    else
    {
        switch(remaining[0])
        {
            case 1:
                strcpy(possible, " ");
                break;
            case 2:
                strcpy(possible, "abc");
                break;
            case 3:
                strcpy(possible, "def");
                break;
            case 4:
                strcpy(possible, "ghi");
                break;
            case 5:
                strcpy(possible, "jkl");
                break;
            case 6:
                strcpy(possible, "mno");
                break;
            case 7:
                strcpy(possible, "pqrs");
                break;
            case 8:
                strcpy(possible, "tuv");
                break;
            case 9:
                strcpy(possible, "wxyz");
                break;
            case 0:
                strcpy(possible, "+");
                break;
            default:
                break;
        }
        for(int i = 0; i < strlen(possible); i++)
        {
            tmp = malloc(sizeof(char)*(strlen(previous) + 2));
            strcpy(tmp, previous);
            tmp[strlen(previous)] = possible[i];
            tmp[strlen(previous)+1] = '\0';
            decode(numRemaining-1, &remaining[1], tmp);
        }
    }
}

int main(void)
{  
    char word[DIGITS + 1]; 
    word[0] = '\0';
    int code[DIGITS];
    for(int i = 0; i < DIGITS; i++)
    {
        scanf("%d", &code[i]);
    }
    decode(DIGITS, code, word);
    return 0;
}


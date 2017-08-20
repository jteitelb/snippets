#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 127

void caesar(char* plaintext, int shift);

int main(int argc, char* argv[])
{
    int shift;
    char input[MAX_LENGTH];    

    shift = (argc == 1)? 13 : atoi(argv[1]);
    printf("Plaintext:\n");
    scanf("%s", &input);
    caesar(input, shift);
    printf("Ciphertext:\n");
    printf("%s\n", input);
    return 0;
}

void caesar(char* plaintext, int shift)
{
    if (shift < 0)
    {
        shift = shift + 26;
    }
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++)
    {
        int new = plaintext[i] + shift;
        if (new > 'z')
        {
            new -= 26;
        }
        plaintext[i] = new;
    }
}


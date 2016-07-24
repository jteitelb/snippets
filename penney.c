#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define LENGTH 3  // length of sequences chosen
#define NUM_ROUNDS 10000

typedef struct Player
{
    char sequence[LENGTH];
    int wins;
} Player;

void getSequence(Player* playerA, Player* playerB);
int compareSequence(char* sequence1, char* sequence2);
void simulateMatchup(int sequence1, int sequence2);
void playRound(Player* playerA, Player* playerB);
void generateSequence(int sequence, char* stringForm);

int main(void)
{
    // for interactive play
    /*
    Player playerA;
    Player playerB;
    char first = 1;

    playerA.wins = 0;
    playerB.wins = 0;
    do
    {
        if (!first)
        {
            printf("Sequences cannot be the same. Please try again. \n");
        }
        getSequence(&playerA, &playerB); 
        first = 0;
    }
    while (compareSequence(playerA.sequence, playerB.sequence));
    */
    char sequence[LENGTH+1];
    sequence[LENGTH] = '\0';

    for(int i = 0; i < 8; i++)
    {
        generateSequence(i, sequence);
        printf("\t%s", sequence);
    }
    printf("\n");

    srand(time(NULL));
    for(int i = 0; i < 8; i++)
    {
        generateSequence(i, sequence);
        printf("%s\t", sequence);
        for(int j = 0; j < i; j++)
        {
            simulateMatchup(i, j);
            printf("\t");
        }
        printf("\n");
    }
    
    /*
    printf("in main, player A:\n");
    for (int j = 0; j < LENGTH; j++)
    {
        printf("%c", playerA.sequence[j]);
    }
    printf("\n");
    printf("in main, player B:\n");
    for (int j = 0; j < LENGTH; j++)
    {
        printf("%c", playerB.sequence[j]);
    }
    printf("\n");
    */

    //for interactive play
    /*
    for (int i = 0; i < NUM_ROUNDS; i++)
    {
        printf("Starting Round %d:\n", i + 1);
        playRound(&playerA, &playerB);
    }
    printf("Results:\n");
    printf("Player A: %d wins\nPlayer B: %d wins\n", playerA.wins, playerB.wins);
    */
}

void simulateMatchup(int sequence1, int sequence2)
{
    Player playerA;
    Player playerB;

    playerA.wins = 0;
    playerB.wins = 0;
    generateSequence(sequence1, playerA.sequence);
    generateSequence(sequence2, playerB.sequence);
    
    /*
    printf("in main, player A:\n");
    for (int j = 0; j < LENGTH; j++)
    {
        printf("%c", playerA.sequence[j]);
    }
    printf("\n");
    printf("in main, player B:\n");
    for (int j = 0; j < LENGTH; j++)
    {
        printf("%c", playerB.sequence[j]);
    }
    printf("\n");
    */
    for (int i = 0; i < NUM_ROUNDS; i++)
    {
        //printf("Starting Round %d:\n", i + 1);
        playRound(&playerA, &playerB);
    }
    //printf("Results:\n");
    //printf("Player A: %d wins\nPlayer B: %d wins\n", playerA.wins, playerB.wins);
    printf("%.3f", playerA.wins/(float)NUM_ROUNDS);

}

void playRound(Player* playerA, Player* playerB)
{
    char last[LENGTH];
    for(int i = 0; i < LENGTH; i++)
    {
        last[i] = rand()%2 == 0? 'H' : 'T';
        //printf("%c", last[i]); //test
    }
    while(1) // This program can run forever... sort of
    {
        if (compareSequence(playerA->sequence, last))
        {
            //printf("\nPlayer A wins!\n"); //test
            playerA->wins++;
            return;
        }
        if (compareSequence(playerB->sequence, last))
        {
            //printf("\nPlayer B wins!\n"); //test
            playerB->wins++;
            return;
        }
        for (int i = 0; i < LENGTH - 1; i++)
        {
            last[i] = last[i+1];
        }
        last[LENGTH-1] = rand()%2 == 0? 'H' : 'T';
        //printf("%c", last[LENGTH-1]); //test
    }
}

void getSequence(Player* playerA, Player* playerB)
{
    char temp[LENGTH];
    for (int i = 0; i < 2; i++)
    {
        printf("Please enter a sequence for player %c:\n", 'A' + i);
        for (int j = 0; j < LENGTH; j++)
        {
            scanf("%c", &temp[j]);
            if (toupper(temp[j]) != 'H' && toupper(temp[j]) != 'T')
            {
                while (getchar() != '\n');
                j = -1;
                printf("Please enter a valid input for player %c's sequence:\n", 'A' + i);
                continue;
            }
        }
        while (getchar() != '\n');
        if (i == 0)
        {
            for(int j = 0; j < LENGTH; j++)
            {
                playerA->sequence[j] = toupper(temp[j]);
            }
        }
        else
        {
            for(int j = 0; j < LENGTH; j++)
            {
                playerB->sequence[j] = toupper(temp[j]);
            }
        }
        /*
        for (int j = 0; j < LENGTH; j++)
        {
            printf("%c", temp[j]);
        }
        printf("\n");
        */
    }
}

int compareSequence(char* sequence1, char* sequence2)
{
    for(int i = 0; i < LENGTH; i++)
    {
        if (sequence1[i] != sequence2[i])
        {
            return 0;
        }
    }
    return 1;
}

void generateSequence(int sequence, char* stringForm)
{
    for (int i = 0; i < LENGTH; i++)
    {
        stringForm[LENGTH - i - 1] = sequence % 2 == 0? 'H' : 'T';
        sequence /= 2;
    }
}

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct position
{
    int x;
    int y;
} position;

typedef struct vertex
{
    position pos;
    int distance;
    struct node *prev;
} vertex;

position randomPosition(int xMax, int yMax);

int main(int argc, char* argv[])
{
    int i, j;
    int index, startIndex;
    position start;
    position end;
    position current;
    vertex tmp;
    vertex list[MAX*MAX];
    srand(time(NULL)); 

    start = randomPosition(MAX,MAX);
    end = randomPosition(MAX,MAX);

    current = start;

    index = 0;
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            list[index].pos.x = i;
            list[index].pos.y = j;
            list[index].distance = INT_MAX;
            list[index].prev = NULL;
            index++;
        }
    }
    startIndex = start.x * MAX + start.y;
    list[startIndex].distance = 0;


    printf( "start: (%d, %d)\nend: (%d, %d)\n", start.x, start.y, end.x, end.y );
    return 0;
}

position randomPosition(int xMax, int yMax)
{
    position randomPos;
    randomPos.x = rand() % xMax;
    randomPos.y = rand() % yMax;
    return randomPos;
}

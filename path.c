#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

typedef struct position
{
    int x;
    int y;
} position;

position randomPosition(int xMax, int yMax);

int main(int argc, char* argv[])
{
    position start;
    position end;
    position current;
    srand(time(NULL)); 

    start = randomPosition(MAX,MAX);
    end = randomPosition(MAX,MAX);

    current = start;

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

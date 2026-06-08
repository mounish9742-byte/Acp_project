#include <stdio.h>

#define ROWS 20
#define COLS 50

void initializeCanvas(char canvas[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas(char canvas[ROWS][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char canvas[ROWS][COLS];

    initializeCanvas(canvas);

    printf("Empty Canvas:\n");
    displayCanvas(canvas);

    return 0;
}
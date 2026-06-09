#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 25
#define COLS 80

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

void drawRectangle(char canvas[ROWS][COLS],
                   int x, int y,
                   int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            if(i == y || i == y + height - 1 ||
               j == x || j == x + width - 1)
            {
                canvas[i][j] = '*';
            }
        }
    }
}

void drawLine(char canvas[ROWS][COLS],
              int x1, int y1,
              int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = (dx > dy) ? dx : dy;

    float xInc = (float)(x2 - x1) / steps;
    float yInc = (float)(y2 - y1) / steps;

    float x = x1;
    float y = y1;

    int i;

    for(i = 0; i <= steps; i++)
    {
        if((int)y >= 0 && (int)y < ROWS &&
           (int)x >= 0 && (int)x < COLS)
        {
            canvas[(int)y][(int)x] = '*';
        }

        x += xInc;
        y += yInc;
    }
}

void drawTriangle(char canvas[ROWS][COLS],
                  int x, int y,
                  int size)
{
    int i;

    for(i = 0; i < size; i++)
    {
        if(y + i < ROWS)
        {
            if(x - i >= 0)
                canvas[y + i][x - i] = '*';

            if(x + i < COLS)
                canvas[y + i][x + i] = '*';
        }
    }

    for(i = x - size + 1; i <= x + size - 1; i++)
    {
        if(y + size - 1 < ROWS &&
           i >= 0 && i < COLS)
        {
            canvas[y + size - 1][i] = '*';
        }
    }
}

void drawCircle(char canvas[ROWS][COLS],
                int cx, int cy,
                int r)
{
    int x, y;

    for(y = 0; y < ROWS; y++)
    {
        for(x = 0; x < COLS; x++)
        {
            int d = (x - cx) * (x - cx)
                  + (y - cy) * (y - cy);

            if(abs(d - r * r) <= r)
            {
                canvas[y][x] = '*';
            }
        }
    }
}

void deleteArea(char canvas[ROWS][COLS],
                int x, int y,
                int width, int height)
{
    int i, j;

    for(i = y; i < y + height && i < ROWS; i++)
    {
        for(j = x; j < x + width && j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

int main()
{
    char canvas[ROWS][COLS];

    int choice;

    initializeCanvas(canvas);

    while(1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Modify Rectangle\n");
        printf("7. Display Picture\n");
        printf("8. Clear Canvas\n");
        printf("9. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                int x, y, w, h;

                printf("Enter x y width height: ");
                scanf("%d%d%d%d", &x, &y, &w, &h);

                drawRectangle(canvas, x, y, w, h);
                break;
            }

            case 2:
            {
                int x1, y1, x2, y2;

                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

                drawLine(canvas, x1, y1, x2, y2);
                break;
            }

            case 3:
            {
                int x, y, size;

                printf("Enter top x y and size: ");
                scanf("%d%d%d", &x, &y, &size);

                drawTriangle(canvas, x, y, size);
                break;
            }

            case 4:
            {
                int cx, cy, r;

                printf("Enter center x y and radius: ");
                scanf("%d%d%d", &cx, &cy, &r);

                drawCircle(canvas, cx, cy, r);
                break;
            }

            case 5:
            {
                int x, y, w, h;

                printf("Enter x y width height to delete: ");
                scanf("%d%d%d%d", &x, &y, &w, &h);

                deleteArea(canvas, x, y, w, h);
                break;
            }

            case 6:
            {
                int oldx, oldy, oldw, oldh;
                int newx, newy, neww, newh;

                printf("Old Rectangle (x y width height): ");
                scanf("%d%d%d%d",
                      &oldx, &oldy, &oldw, &oldh);

                deleteArea(canvas,
                           oldx, oldy,
                           oldw, oldh);

                printf("New Rectangle (x y width height): ");
                scanf("%d%d%d%d",
                      &newx, &newy,
                      &neww, &newh);

                drawRectangle(canvas,
                              newx, newy,
                              neww, newh);

                break;
            }

            case 7:
                displayCanvas(canvas);
                break;

            case 8:
                initializeCanvas(canvas);
                printf("Canvas Cleared!\n");
                break;

            case 9:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
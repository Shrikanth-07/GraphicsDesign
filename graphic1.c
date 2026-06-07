#include <stdio.h>

#define ROWS 25
#define COLS 80

char data[ROWS][COLS];

void initializedata()
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            data[i][j] = ' ';
        }
    }
}

void displayimage()
{
    int i, j;

    printf("\n----- IMAGE -----\n");

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", data[i][j]);
        }
        printf("\n");
    }
}

void drawStraightline(int x1, int y1, int x2, int y2)
{
    int i;

    if(x1 == x2)
    {
        if(y1 > y2)
        {
            int temp = y1;
            y1 = y2;
            y2 = temp;
        }

        for(i = y1; i <= y2; i++)
        {
            if(i >= 0 && i < ROWS && x1 >= 0 && x1 < COLS)
                data[i][x1] = '*';
        }
    }
    else if(y1 == y2)
    {
        if(x1 > x2)
        {
            int temp = x1;
            x1 = x2;
            x2 = temp;
        }

        for(i = x1; i <= x2; i++)
        {
            if(y1 >= 0 && y1 < ROWS && i >= 0 && i < COLS)
                data[y1][i] = '*';
        }
    }
    else
    {
        printf("Only horizontal and vertical lines are supported.\n");
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    int i;

    for(i = x; i < x + width; i++)
    {
        if(y >= 0 && y < ROWS && i >= 0 && i < COLS)
            data[y][i] = '*';

        if(y + height - 1 >= 0 && y + height - 1 < ROWS &&
           i >= 0 && i < COLS)
            data[y + height - 1][i] = '*';
    }

    for(i = y; i < y + height; i++)
    {
        if(i >= 0 && i < ROWS && x >= 0 && x < COLS)
            data[i][x] = '*';

        if(i >= 0 && i < ROWS &&
           x + width - 1 >= 0 &&
           x + width - 1 < COLS)
        {
            data[i][x + width - 1] = '*';
        }
    }
}

void drawTriangle(int row, int col, int height)
{
    int i, j;

    for(i = 0; i < height; i++)
    {
        for(j = col - i; j <= col + i; j++)
        {
            if(i == height - 1 ||
               j == col - i ||
               j == col + i)
            {
                if(row + i >= 0 &&
                   row + i < ROWS &&
                   j >= 0 &&
                   j < COLS)
                {
                    data[row + i][j] = '*';
                }
            }
        }
    }
}

int main()
{
    int choice;

    initializedata();

    do
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("0. Exit\n");
        printf("1. Display Image\n");
        printf("2.Draw Line\n");
        printf("3.Draw Rectangle\n"); 
        printf("4.Draw Triangle\n"); 
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {

            case 0:
                printf("Exiting Program...\n");
                break;
            case 1:
                displayimage();
                break;
            case 2:
            {
                int x1,y1,x2,y2;
                printf("Enter x1 y1 x2 y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

                drawStraightline(x1,y1,x2,y2);
                break;
            }
            case 3:
            {
                int x, y, width, height;

                printf("Enter x y width height: ");
                scanf("%d%d%d%d", &x, &y, &width, &height);

                drawRectangle(x, y, width, height);
                break;
            }
            case 4:
            {
                 int row, col, height;

                printf("Enter row column height: ");
                scanf("%d%d%d", &row, &col, &height);

                drawTriangle(row, col, height);
                break;
            }    

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 0);

    return 0;
}
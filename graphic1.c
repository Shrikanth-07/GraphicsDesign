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

int main()
{
    int choice;

    initializedata();

    do
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("0. Exit\n");
        printf("1. Display Image\n");
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

            default:
                printf("Invalid Choice\n");
        }

    } while(choice != 0);

    return 0;
}
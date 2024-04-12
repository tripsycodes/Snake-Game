#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int Height = 20, Width = 20;
int snake_x, snake_y, food_x, food_y, score;
char flag;
int game = 0;

void title()
{
    printf("******* WELCOME *******");
    printf("\n          TO           ");
    printf("\n**** THE SNAKE GAME ****");
    printf("\n\n\n\n");
    printf("1. Play Game\n2. Rules and Guidelines");
}

void begin()
{
    game = 1;
    score = 0;
    snake_x = 1 + (rand() % 19);
    snake_y = 1 + (rand() % 19);
    food_x = 1 + (rand() % 19);
    food_y = 1 + (rand() % 19);
}

void draw()
{
    system("cls");
    int width = 0, height = 0;
    printf("Score: %d", score);
    while (width < Width)
    {
        while (height < Height)
        {
            if (width == 0 || width == Width - 1 || height == 0 || height == Height - 1)
                printf("$");
            else if (width == snake_x && height == snake_y)
                printf("O");
            else if (width == food_x && height == food_y)
                printf("@");
            height++;
        }
        width++;
    }
}

void controls()
{
    if (kbhit())
    {
        switch (getch())
        {
        case '4':
            flag = 'l';
            break;
        case '8':
            flag = 'u';
            break;
        case '6':
            flag = 'r';
            break;
        case '2':
            flag = 'd';
            break;
        }
    }
}

void logic()
{
    if (flag == 'l')
        snake_x--;
    else if (flag == 'u')
        snake_y--;
    else if (flag == 'r')
        snake_x++;
    else if (flag == 'd')
        snake_y++;

    if (snake_x == food_x && snake_y == food_y)
    {
        score++;
        food_x = 1 + (rand() % 19);
        food_y = 1 + (rand() % 19);
    }
}

int main()
{
    begin();
    while (game = 1)
    {
        draw();
        controls();
        logic();
        if (snake_x == 0 || snake_x == Width || snake_y == 0 || snake_y == Height)
        {
            printf("GAME OVER");
            game = 0;
        }
        for (int m = 0; m < 2000; m++)
        {
            for (int n = 0; n < 2000; n++)
            {
            }
        }
    }
}
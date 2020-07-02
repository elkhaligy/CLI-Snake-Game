#include <iostream>
#include <conio.h>
#include<windows.h>
using namespace std;
bool game_over;
//board
const int width = 20;
const int height = 10;
//snake head
int x, y;
//fruit
int fruit_x, fruit_y;
//directions
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
//other
int score;

//tail
int tail_x[100],tail_y[100];
int n_tail;
void setup()
{
    game_over = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruit_x = rand() % (width-2);
    fruit_y = rand() % (height-2);
    score = 0;
}
void draw()
{
    system("cls");
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
 

    //2 Nested loops scanning entire board
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
          
            if (j == 0)
                cout << "#";
         
            if (i == y && j == x)
                cout << "O";
            else if (i == fruit_y && j == fruit_x)
                cout << "F";
            
            else
            {
                bool print = false;
                for (int k = 0; k < n_tail; k++)
                {
                    if (tail_x[k] == j && tail_y[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if(!print)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "#";


        }
        cout << endl;
    }

    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score;
}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case'a':
            dir = LEFT;
            break;
        case'd':
            dir = RIGHT;
            break;
        case's':
            dir = DOWN;
            break;
        case'w':
            dir = UP;
            break;
        case'x':
            game_over = true;
            break;
        }
    }
}
void logic()
{

    int prev_x = tail_x[0];
    int prev_y = tail_y[0];
    int prev2_x, prev2_y;
    tail_x[0] = x;
    tail_y[0] = y;
    for (int i = 1; i < n_tail; i++)
    {
        prev2_x = tail_x[i];
        prev2_y = tail_y[i];
        tail_x[i] = prev_x;
        tail_y[i] = prev_y;
        prev_x = prev2_x;
        prev_y = prev2_y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

  //  if (x > width || x<0 || y>height || y < 0)
    //    game_over = true;
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width;
    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height;
    for (int i = 0; i < n_tail; i++)
        if (tail_x[i] == x && tail_y[i] == y)
            game_over = true;
    if (x == fruit_x && y == fruit_y)
    {
      
        score += 10;
        fruit_x = rand() % (width-2);
        fruit_y = rand() % (height-2);
        n_tail++;
    }
}
int main()
{
    setup();
    while(!game_over)
    {
        draw();
        input();
        logic();
        Sleep(10);
    }
}


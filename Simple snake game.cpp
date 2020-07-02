#include <iostream>
bool game_over;
//board
const int width = 20;
const int height = 20;
//snake head
int x, y;
//fruit
int fruit_x, fruit_y;
//directions
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
//other
int score;
void setup()
{
    game_over = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruit_x = rand() % width;
    fruit_y = rand() % height;
    score = 0;
}
void draw()
{
    system("cls");
   
}
void input()
{

}
void logic()
{

}
int main()
{
    setup();
    while(!game_over)
    {
        draw();
        input();
        logic();
    }
}


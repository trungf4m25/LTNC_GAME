#include <iostream>
#include <conio.h>
#include <ctime>

#include "Snake.h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;
int score = 0;
bool gameOver = false;

void board()
{
    COORD snakePos = snake.getPos();
    COORD foodPos = food.getPos();
    deque<COORD> snakeBody = snake.getBody();
    cout << "SCORE : " << score << "\n\n";
    for(int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t\t\t#";
        for(int j = 0; j < WIDTH - 2; j++)
        {
            if(i == 0 || i == HEIGHT - 1) cout << '#';
            else if(i == snakePos.Y && j + 1 == snakePos.X) cout << '0';
            else if(i == foodPos.Y && j + 1 == foodPos.X) cout << '@';
            else
            {
                bool isBodyPart = false;
                int snakeBodySize = snakeBody.size();
                for(int k = 0; k < snakeBodySize - 1; k++)
                {
                    if(i == snakeBody[k].Y && j + 1 == snakeBody[k].X)
                    {
                        cout << 'o';
                        isBodyPart = true;
                        break;
                    }
                }
                if(!isBodyPart) cout << ' ';
            }
        }
        cout << "#\n";
    }
}

void Game()
{
    food.genFood();
    while(!gameOver)
    {
        board();
        if(kbhit())
        {
            switch(getch())
            {
                case 'w':
                    {
                        snake.direction('u');
                        break;
                    }
                case 'a':
                    {
                        snake.direction('l');
                        break;
                    }
                case 's':
                    {
                        snake.direction('d');
                        break;
                    }
                case 'd':
                    {
                        snake.direction('r');
                        break;
                    }
                case 72 :
                    {
                        snake.direction('u');
                        break;
                    }
                case 75 :
                    {
                        snake.direction('l');
                        break;
                    }
                case 80 :
                    {
                        snake.direction('d');
                        break;
                    }
                case 77 :
                    {
                        snake.direction('r');
                        break;
                    }
            }
        }
        if(snake.collided()) gameOver = true;
        if(snake.eaten(food.getPos()))
        {
            food.genFood();
            snake.grow();
            score += 10;
        }
        snake.moveSnake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
}

int main()
{
    srand(time(NULL));
    Game();
    return 0;
}

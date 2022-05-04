#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
    this->pos = pos;
    this->vel = vel;
    dir = 'n';
    len = 1;
    body.push_back(pos);
}

void Snake::direction(char dir)
{
    this->dir = dir;
}

void Snake::grow()
{
    len++;
}

COORD Snake::getPos()
{
    return pos;
}

vector<COORD> Snake::getBody()
{
    return body;
}

void Snake::moveSnake()
{
    switch(dir)
    {
        case 'u':
            {
                pos.Y -= vel;
                break;
            }
        case 'd':
            {
                pos.Y += vel;
                break;
            }
        case 'l':
            {
                pos.X -= vel;
                break;
            }
        case 'r':
            {
                pos.X += vel;
                break;
            }
    }
    // Snake goes through the wall
    if(pos.X > WIDTH - 2) pos.X = 1;
    if(pos.X < 1) pos.X = WIDTH - 2;
    if(pos.Y > HEIGHT - 2) pos.Y = 1;
    if(pos.Y < 1) pos.Y = HEIGHT - 2;

    body.push_back(pos);
    int bodysize = body.size();
    if(bodysize > len) body.erase(body.begin());
}

bool Snake::collided()
{
    if(pos.X < 1 || pos.X > WIDTH - 2 || pos.Y < 1 || pos.Y > HEIGHT - 2) return true;
    for(int i = 0; i < len - 1; i++)
    {
        if(pos.X == body[i].X && pos.Y == body[i].Y) return true;
    }
    return false;
}

bool Snake::eaten(COORD food)
{
    if(pos.X == food.X && pos.Y == food.Y) return true;
    return false;
}

#include "Ball.h"
#include "ConsoleHelper.h"
#include<iostream>

using namespace std;

Ball::Ball(int x, int y)
{
    point.x = x;
    point.y = y;

    ConsoleHelper::GetConsoleSize(consoleRows, consoleColumns);
}

void Ball::Show()
{
    ConsoleHelper::SetCursorPosition(point.x, point.y);
    
    ConsoleHelper::SetConsoleColor(ConsoleColor::DarkRed);
    cout << '@';
    ConsoleHelper::ResetConsoleColor();
}

void Ball::Hide()
{
    ConsoleHelper::SetCursorPosition(point.x, point.y);
    cout << ' ';
}

void Ball::Move()
{
    Hide();

    int newX = point.x + _xFactor;
    int newY = point.y + _yFactor;

    if (newX < 0)
        _xFactor = -_xFactor;

    if (newX >= consoleColumns)
        _xFactor = -_xFactor;

    if (newY < 0)
        _yFactor = -_yFactor;

    if (newY >= consoleRows)
        _yFactor = -_yFactor;

    point.x += _xFactor;
    point.y += _yFactor;

    Show();
    Sleep(SpeedBrake);
}
#include <iostream>
#include "Bar.h"
#include "ConsoleHelper.h"

using namespace std;

Bar::Bar()
{
    _barText = string(Width, ' ');

    ConsoleHelper::GetConsoleSize(consoleRows, consoleColumns);

    _point.x = (consoleColumns - Width) / 2;
    _point.y = consoleRows - Height;
}

void Bar::Show()
{
    ConsoleHelper::SetCursorPosition(_point.x, _point.y);
    ConsoleHelper::SetConsoleColor(ConsoleColor::Gray, BarColor);
    cout << _barText;
    ConsoleHelper::ResetConsoleColor();
}

void Bar::Hide()
{
    ConsoleHelper::SetCursorPosition(_point.x, _point.y);
    cout << _barText;
}

void Bar::MoveLeft()
{
    Hide();

    int newX = _point.x - Speed;
    _point.x = newX < 0 ? 0 : newX;

    Show();
}

void Bar::MoveRight()
{
    Hide();

    int newX = _point.x + Speed;
    _point.x = newX > consoleColumns - Width - 2 ? consoleColumns - Width - 2 : newX;

    Show();
}

bool Bar::DoesItIntersect(Point ballPoint)
{
    return ballPoint.x >= _point.x && ballPoint.x <= getRight();
}

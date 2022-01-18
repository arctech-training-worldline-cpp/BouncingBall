#include "Score.h"
#include "ConsoleHelper.h"
#include <string>
#include <iostream>

using namespace std;

Score::Score()
{
    _points = 0;
    _lives = MaxLives;
}

Score Score::operator++()
{
    _points++;
    return *this;
}

Score Score::operator--()
{
    _lives--;
    return *this;
}

void Score::Show()
{
    ConsoleHelper::SetCursorPosition(0, 0);
    cout << "Score:" << _points << " | Lives:" << _lives;
}
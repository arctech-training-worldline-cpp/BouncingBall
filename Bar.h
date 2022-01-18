#include <iostream>
#include <string>
#include "Point.h"
#include "ConsoleHelper.h"

class Bar
{
private:
    const int Width = 20;
    const int Height = 1;
    const int Speed = 5;
    const ConsoleColor BarColor = ConsoleColor::Cyan;

    std::string _barText;
    Point _point;

    int consoleRows, consoleColumns;

public:
    int getRight()
    {
        return _point.x + Width;
    }

    Bar();

    void Show();
    void Hide();
    void MoveLeft();
    void MoveRight();
    bool DoesItIntersect(Point ballPoint);
};
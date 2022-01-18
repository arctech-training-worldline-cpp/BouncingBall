#include "Point.h"

class Ball
{
private:
    int _xFactor = 3;
    int _yFactor = 1;

    const int SpeedBrake = 50;

    int consoleRows, consoleColumns;

public:
    Point point;

    Ball(int x, int y);
    void Show();
    void Hide();
    void Move();
};
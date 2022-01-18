#ifndef __POINT_H
#define __POINT_H

struct Point
{
    public:
        int x;
        int y;

        Point()
        {
            
        }

        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
};

#endif
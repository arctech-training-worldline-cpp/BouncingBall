#include <iostream>
#include "Score.h"
#include "Bar.h"
#include "Ball.h"
#include "ConsoleHelper.h"
#include "BannerHelper.h"

using namespace std;

void TestScore()
{
    Score score;

    score.Show();

    cout << "\nPress enter key to continue." << endl;
    ConsoleHelper::ReadEnterKey();

    ++score;

    --score;

    score.Show();

    cout << "\nPress any key to continue." << endl;
    ConsoleHelper::ReadKey();
}

void TestBanner()
{
    BannerHelper::ShowStartGameBanner();
    BannerHelper::ShowEndGameBanner();
}

void TestBar()
{
    BannerHelper::ShowStartGameBanner();

    Bar bar;

    bar.Show();

    KeyInfo keyInfo;

    do
    {
        keyInfo = ConsoleHelper::ReadKey();

        if (keyInfo.IsSpecialKey)
        {
            switch (keyInfo.SpecialKey)
            {
            case ConsoleSpecialKey::KeyLeftArrow:
                bar.MoveLeft();
                break;
            case ConsoleSpecialKey::KeyRightArrow:
                bar.MoveRight();
                break;
            }
        }
        else
        {
            switch (keyInfo.Key)
            {
            case 'S':
            case 's':
                bar.Show();
                break;
            case 'H':
            case 'h':
                bar.Hide();
                break;
            }
        }

    } while (keyInfo.SpecialKey != ConsoleSpecialKey::KeyEscape);
}

void TestBall()
{
    BannerHelper::ShowStartGameBanner();

    Ball ball(10, 5);

    do
    {
        ball.Move();
    } while (true);
}

int main()
{
    TestScore();
    //TestBanner();
    TestBar();
    TestBall();

    ConsoleHelper::ReadKey();

    return 0;
}

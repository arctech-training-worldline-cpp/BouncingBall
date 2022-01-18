#include "ConsoleHelper.h"
#include <iostream>
#include <limits>

using namespace std;

void ConsoleHelper::SetCursorPosition(short x, short y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}

void ConsoleHelper::Clear()
{
    system("CLS");
}

void ConsoleHelper::ReadEnterKey()
{
    char ch;
    do
    {
        ch = getch();
    } while (ch != '\r');
}

KeyInfo ConsoleHelper::ReadKey()
{    
    int ch = getch();
    if(ch == 224)
    {
        ch = getch();
        
        switch(ch)
        {
            case ConsoleSpecialKey::KeyLeftArrow:
                return KeyInfo(ConsoleSpecialKey::KeyLeftArrow);
            case ConsoleSpecialKey::KeyRightArrow:
                return KeyInfo(ConsoleSpecialKey::KeyRightArrow);
            default:
                return KeyInfo(ConsoleSpecialKey::KeyOther);
        }
    }
    else if(ch == ConsoleSpecialKey::KeyEscape)
        return KeyInfo(ConsoleSpecialKey::KeyEscape);
    else
        return KeyInfo(ch);
}

void ConsoleHelper::GetConsoleSize(int &rows, int &columns)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void ConsoleHelper::SetConsoleColor(ConsoleColor foreground, ConsoleColor background)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    WORD color = foreground | (background << 4);
    SetConsoleTextAttribute(hConsole, color);
}

bool ConsoleHelper::GetConsoleColor(short &ret)
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
        return false;
    ret = info.wAttributes;
    return true;
}

void ConsoleHelper::ResetConsoleColor()
{
    SetConsoleColor(ConsoleColor::Gray);
}

KeyInfo::KeyInfo()
{
    Key = 0;
    SpecialKey = ConsoleSpecialKey::KeyNone;
    IsSpecialKey = false;
}

KeyInfo::KeyInfo(char key)
{    
    Key = key;
    SpecialKey = ConsoleSpecialKey::KeyNone;
    IsSpecialKey = false;
}

KeyInfo::KeyInfo(ConsoleSpecialKey specialKey)
{
    Key = 0;
    SpecialKey = specialKey;
    IsSpecialKey = true;
}
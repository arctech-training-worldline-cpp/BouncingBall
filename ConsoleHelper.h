#pragma once
#include <conio.h>
#include <windows.h>

enum ConsoleColor
{
    Black = 0,
    DarkBlue = 1,
    DarkGreen = 2,
    DarkCyan = 3,
    DarkRed = 4,
    DarkMagenta = 5,
    DarkYellow = 6,
    Gray = 7,
    DarkGray = 8,
    Blue = 9,
    Green = 10,
    Cyan = 11,
    Red = 12,
    Magenta = 13,
    Yellow = 14,
    White = 15
};

enum ConsoleSpecialKey
{
    KeyNone = 0,
    KeyEscape = 27,
    KeyLeftArrow = 75,
    KeyRightArrow = 77,
    KeyOther = 255
};

struct KeyInfo
{
    public:
        bool IsSpecialKey;
        char Key;
        ConsoleSpecialKey SpecialKey;
        
        KeyInfo();
        KeyInfo(char key);
        KeyInfo(ConsoleSpecialKey specialKey);
};

class ConsoleHelper
{
public:
    static void SetCursorPosition(short x, short y);
    static void Clear();
    static void ReadEnterKey();
    static KeyInfo ReadKey();
    static void GetConsoleSize(int &rows, int &columns);
    static void SetConsoleColor(ConsoleColor foreground, ConsoleColor background = ConsoleColor::Black);
    static bool GetConsoleColor(short &ret);
    static void ResetConsoleColor();
};
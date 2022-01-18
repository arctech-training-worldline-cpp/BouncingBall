#include "BannerHelper.h"
#include "ConsoleHelper.h"
#include "Point.h"
#include <iostream>
#include <wincon.h>

using namespace std;

void BannerHelper::ShowStartGameBanner()
{
    vector<string> bannerText =
    {
        " __      __       .__                                  __          ",
        "/  \\    /  \\ ____ |  |   ____  ____   _____   ____   _/  |_  ____  ",
        "\\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\  \\   __\\/  _ \\ ",
        " \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/   |  | (  <_> )",
        "  \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >  |__|  \\____/ ",
        "       \\/       \\/          \\/            \\/     \\/                ",
        "  __  .__               ________                       ",
        "_/  |_|  |__   ____    /  _____/_____    _____   ____  ",
        "\\   __\\  |  \\_/ __ \\  /   \\  ___\\__  \\  /     \\_/ __ \\ ",
        " |  | |   Y  \\  ___/  \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ ",
        " |__| |___|  /\\___  >  \\______  (____  /__|_|  /\\___  >",
        "           \\/     \\/          \\/     \\/      \\/     \\/ "
    };

    DrawBanner(bannerText);
}

void BannerHelper::ShowEndGameBanner()
{
    vector<string> endGameBannerText =
    {
        "  ________                        .__                   ",
        " /  _____/_____    _____   ____   |  |__ _____    ______",
        "/   \\  ___\\__  \\  /     \\_/ __ \\  |  |  \\\\__  \\  /  ___/",
        "\\    \\_\\  \\/ __ \\|  Y Y  \\  ___/  |   Y  \\/ __ \\_\\___ \\ ",
        " \\______  (____  /__|_|  /\\___  > |___|  (____  /____  >",
        "        \\/     \\/      \\/     \\/       \\/     \\/     \\/ ",
        "                   .___         .___",
        "  ____   ____    __| _/____   __| _/",
        "_/ __ \\ /    \\  / __ |/ __ \\ / __ | ",
        "\\  ___/|   |  \\/ /_/ \\  ___// /_/ | ",
        " \\___  >___|  /\\____ |\\___  >____ | ",
        "     \\/     \\/      \\/    \\/     \\/ "
    };

    DrawBanner(endGameBannerText);
}

void BannerHelper::DrawBanner(vector<string> bannerText)
{
    ConsoleHelper::Clear();

    int lineCount = bannerText.size();
    int consoleRows, consoleColumns;
    ConsoleHelper::GetConsoleSize(consoleRows, consoleColumns);

    Point point(0, (consoleRows - lineCount) / 2);

    ConsoleHelper::SetConsoleColor(ConsoleColor::Cyan);

    for (const string &text : bannerText)
    {
        point.x = (consoleColumns - text.length()) / 2;
        ConsoleHelper::SetCursorPosition(point.x, point.y);
        cout << text;
        point.y++;
    }

    ConsoleHelper::ResetConsoleColor();
    ConsoleHelper::ReadKey();    
    ConsoleHelper::Clear();
}

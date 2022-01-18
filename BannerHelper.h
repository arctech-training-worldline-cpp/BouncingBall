#include<string>
#include<vector>

class BannerHelper
{
    private:
        static void DrawBanner(std::vector<std::string> bannerText);
    public:
        static void ShowStartGameBanner();
        static void ShowEndGameBanner();
};
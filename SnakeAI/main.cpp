
#include "utils/utils.hpp"
#include "app/application.hpp"
int main()
{
    App app(window_width, window_height, "Snake AI");

    app.Init(30);
    app.Run();
    return 0;
}

#include "utils/utils.hpp"
#include "app/application.hpp"

int main()
{
    App app(window_width, window_height, "Snake AI");

    //change the seed to get different results
    srand(12237);

    app.Init(10);
    app.Run();
    return 0;
}

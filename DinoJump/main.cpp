#include "Application.h"

int main(int argc, char* argv[])
{
    Application app;
    app.Load();
    app.Run();
    app.Unload();

    return 0;
}
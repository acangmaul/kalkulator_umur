#include "app/app.hpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#if !defined(_WIN32) || !defined(_WIN64)
int main()
#else
int WinMain(
    [[maybe_unused]] HINSTANCE hInstance,
    [[maybe_unused]] HINSTANCE hPrevInstance,
    [[maybe_unused]] LPSTR lpCmdLine,
    [[maybe_unused]] int nShowCmd
)
#endif
{
    const App app { "imgl", 400, 120 };
    return app.run();
}
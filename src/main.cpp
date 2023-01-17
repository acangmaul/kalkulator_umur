#include "app/app.hpp"

#if defined(_WIN32) || defined(_WIN64)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#endif

// kalau non-debug dan di windows, jangan spawn console
#if defined(NDEBUG) && (defined(_WIN32) || defined(_WIN64))
int APIENTRY WinMain(
    [[maybe_unused]] HINSTANCE hInstance,
    [[maybe_unused]] HINSTANCE hPrevInstance,
    [[maybe_unused]] LPSTR lpCmdLine,
    [[maybe_unused]] int nShowCmd
)
#else
int main()
#endif
{
    const App app { "Kalkulator Umur", 400, 120 };
    return app.run();
}
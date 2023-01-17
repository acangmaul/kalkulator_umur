#pragma once

#include "ui/window.hpp"

#include <optional>

struct App {
    App(const char* title, int width, int height);
    int run() const;

private:
    std::optional<Window> m_window;
};

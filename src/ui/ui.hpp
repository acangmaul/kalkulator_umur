#pragma once

#include "window.hpp"
#include <functional>

struct GLFWwindow;

struct UI {
    UI(const Window& window, const std::function<void()>& on_imgui_init = nullptr);
    ~UI();

    void begin_frame() const;
    void end_frame() const;

private:
    const Window& m_window;
};

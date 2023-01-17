#pragma once

#include "badge.hpp"

#include <optional>
#include <utility>

struct GLFWwindow;

struct Window {
    Window(Badge<Window>, GLFWwindow* pWindow);
    ~Window();

    Window(Window const&) = delete;
    Window& operator=(Window const&) = delete;

    static std::optional<Window> create(const char* title, int width, int height);

    bool should_open() const;

    GLFWwindow* get_handle() const;
    std::pair<int, int> get_size() const;

    void set_window_size(int width, int height);
    void set_size_constrains(int min_width, int min_height, int max_width = -1 /*GLFW_DONT_CARE*/, int max_height = -1 /*GLFW_DONT_CARE*/);

private:
    GLFWwindow* m_window;
};

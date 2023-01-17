#include "window.hpp"

#include <GLFW/glfw3.h>

Window::Window(Badge<Window>, GLFWwindow* window)
    : m_window(window)
{
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

std::optional<Window> Window::create(const char* title, int width, int height)
{
    // glfwInit can only be called once
    // line below won't be reached if it's already been initialized
    if (!glfwInit()) {
        return {};
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        return {};
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    return std::optional<Window> { std::in_place, Badge<Window> {}, window };
}

bool Window::should_open() const
{
    return !glfwWindowShouldClose(m_window);
}

GLFWwindow* Window::get_handle() const
{
    return m_window;
}

std::pair<int, int> Window::get_size() const
{
    int width = {}, height = {};
    glfwGetWindowSize(m_window, &width, &height);
    return { width, height };
}

void Window::set_window_size(int width, int height)
{
    glfwSetWindowSize(m_window, width, height);
}

void Window::set_size_constrains(int min_width, int min_height, int max_width, int max_height)
{
    glfwSetWindowSizeLimits(m_window, min_width, min_height, max_width, max_height);
}

#include "ui.hpp"

#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

UI::UI(const Window& window, const std::function<void()>& on_imgui_init)
    : m_window(window)
{
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(m_window.get_handle(), true);
    ImGui_ImplOpenGL3_Init();

    if (on_imgui_init) {
        on_imgui_init();
    }
}

UI::~UI()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UI::begin_frame() const
{
    glfwPollEvents();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void UI::end_frame() const
{
    ImGui::Render();
    int width = {}, height = {};
    glfwGetFramebufferSize(m_window.get_handle(), &width, &height);
    glViewport(0, 0, width, height);

    constexpr ImVec4 clear_color = ImVec4 { 0.45f, 0.55f, 0.60f, 1.00f };

    glClearColor(
        clear_color.x * clear_color.w,
        clear_color.y * clear_color.w,
        clear_color.z * clear_color.w,
        clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(m_window.get_handle());
}

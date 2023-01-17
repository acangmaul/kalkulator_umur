#include "app.hpp"
#include "ui/ui.hpp"
#include <string>

#if defined(_WIN32) || defined(_WIN64)
#  define WIN32_LEAN_AND_MEAN
#  include <windows.h>
#endif

#include <imgui/imgui.h>
#include <imgui/imgui_stdlib.h>

App::App(const char* title, int width, int height)
    : m_window(Window::create(title, width, height))
{
}

int App::run() const
{
    if (!m_window) {
        return 1;
    }

    UI ui { *m_window, [] { ImGui::GetIO().IniFilename = nullptr; } };
    std::string umur;

    extern const char jetbrainsmono_compressed_data_base85[];
    ImGui::GetIO()
        .Fonts->AddFontFromMemoryCompressedBase85TTF(jetbrainsmono_compressed_data_base85, 16.f);

    while (m_window->should_open()) {
        ui.begin_frame();

        const auto viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);

        ImGui::Begin("##imgl", nullptr, ImGuiWindowFlags_NoDecoration);
        {
            ImGui::TextUnformatted("Masukkan Umur Anda: ");
            ImGui::SetNextItemWidth(-1.f);
            ImGui::InputText(
                "##age",
                &umur,
                ImGuiInputTextFlags_CallbackCharFilter,
                [](ImGuiInputTextCallbackData* data) -> int {
                    char ch = static_cast<char>(data->EventChar);
                    return !(ch >= '0' && ch <= '9');
                }
            );

            ImGui::Spacing();
            ImGui::Separator();
            ImGui::Spacing();

            constexpr auto credit = "HENGKEL PROJECT";
            const auto credit_text_size = ImGui::CalcTextSize(credit);

            if (ImGui::Button("Hitung", ImVec2(-1.f, -1.f - credit_text_size.y))) {
                // TODO: buat cross platform
                MessageBoxA(
                    nullptr,
                    ("Umur anda adalah " + umur + " tahun").c_str(),
                    "Info",
                    MB_OK | MB_ICONINFORMATION
                );
            }

            ImGui::SetCursorPosX(
                ImGui::GetWindowWidth()
                - credit_text_size.x
                - ImGui::GetScrollX()
                - ImGui::GetStyle().ItemSpacing.x
            );
            ImGui::TextUnformatted(credit);
        }
        ImGui::End();

        ui.end_frame();
    }

    return 0;
}
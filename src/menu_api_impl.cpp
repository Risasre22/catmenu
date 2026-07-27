#include "menu_api_impl.h"

#include "ui.h"


namespace CatMenu
{

REL::Version API::GetVersion()
{
    return API_VER;
}
ImGuiContext* API::GetContext()
{
    return ImGui::GetCurrentContext();
}

APIResult API::RegisterOverlayDrawFunc(const RE::BSString& name, bool (*func)())
{
    return UI::GetSingleton()->RegisterOverlayDrawFunc(name, func);
}

APIResult API::RegisterMenuDrawFunc(const RE::BSString& name, bool (*func)())
{
    return UI::GetSingleton()->RegisterMenuDrawFunc(name, func);
}

void API::InsertNotification(const ImGuiToast& toast)
{
    ImGui::InsertNotification(toast);
}


extern "C" __declspec(dllexport) APIBase* GetAPI()
{
    return API::GetSingleton();
}

// Stable integration exports. These intentionally live outside APIBase so adding
// them does not change its vtable or break existing CatMenu API consumers.
extern "C" __declspec(dllexport) void CatMenu_OpenMenu()
{
    UI::GetSingleton()->OpenMenu();
}

extern "C" __declspec(dllexport) void CatMenu_CloseMenu()
{
    UI::GetSingleton()->CloseMenu();
}

extern "C" __declspec(dllexport) void CatMenu_SetHotkeyEnabled(bool a_enabled)
{
    UI::GetSingleton()->SetHotkeyEnabled(a_enabled);
}

} // namespace CatMenu

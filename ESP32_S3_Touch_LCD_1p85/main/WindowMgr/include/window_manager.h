/**
 * @file window_manager.h
 * @brief Base MVC framework for waveshare ESP32-P4-3.4 circle screen board Application.
 * @author dingjun
 * @date 2025-07-20
 */

#ifndef _WINDOW_MANAGER_H_
#define _WINDOW_MANAGER_H_

#include "base_mvc.h"
#include <stack>
#include <unordered_map>

//namespace esp32_ws {

enum eWindowID {
    kHomeScreen = 0,
    kMp3Screen,
    kMp4Screen,
    kBTScreen,
    kWIFIScreen,
    kSettingsScreen,
    kAboutScreen,
    kMaxWindowID
};

class WindowManager {
public:
    WindowManager() : currentWindowID_(kHomeScreen) {}
    WindowManager(const WindowManager&) = delete;
    WindowManager& operator=(const WindowManager&) = delete;

    void registerWindow(eWindowID id, MVCComponent* mvc);
    void switchToWindow(eWindowID id);
    void goBackWindow();
    void handleCurrentWindowMessage(const stMessage& msg);

private:
    std::unordered_map<eWindowID, MVCComponent*> windows_;
    std::stack<eWindowID> windowStack_;
    eWindowID currentWindowID_;

    MVCComponent* getCurrentMVC();
    MVCComponent* getMVCByID(eWindowID id);
};

//} // end of namespace esp32_ws

#endif
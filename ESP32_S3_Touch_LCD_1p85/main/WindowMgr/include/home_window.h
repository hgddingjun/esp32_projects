/**
 * @file home_window.h
 * @brief Base MVC framework for waveshare ESP32-P4-3.4 circle screen board Application.
 * @author dingjun
 * @date 2025-07-20
 */

#ifndef _HOME_WINDOW_H_
#define _HOME_WINDOW_H_

#include "base_mvc.h"

//namespace esp32_ws {

class HomeModel : public BaseModel {
public:
    void update(const stMessage& msg) override {
        // Handle messages specific to the home model
        // For example, update some state based on the message type
        if (msg.type == kUpdateHome) {
            // Update home model state
        }
    }
};

class HomeView : public BaseView {
public:
    void create(lv_obj_t * parent) override {
        // Create the home screen view
        // For example, create buttons, labels, etc.
    }

    void update() override {
        // Update the home view based on the model state
    }

    void close() override {
        // Clean up resources used by the home view
    }

private:
    lv_obj_t * btnMp3_;
    lv_obj_t * btnMp4_;
    lv_obj_t * btnBT_;
    lv_obj_t * btnWiFi_;
    static void handleHomeButtonClick(lv_event_t * e) {
        // Handle button click events
        lv_obj_t * btn = lv_event_get_target(e);
        stMessage msg;
        msg.type = kButtonClick;
        msg.data = btn; // Pass the button object as data
        MessageCenter::sendMessage(msg);
    }
};

class HomeController : public BaseController {
public:
    void handleMessage(const stMessage& msg) override {
        // Handle messages specific to the home controller
        // For example, respond to button clicks or other events
        if (msg.type == kButtonClick) {
            // Handle button click event
        }
    }
};

// register the home window in the WindowManager
MVCComponent* CreateHomeMVC();

//} // end of namespace esp32_ws
#endif // _HOME_WINDOW_H_
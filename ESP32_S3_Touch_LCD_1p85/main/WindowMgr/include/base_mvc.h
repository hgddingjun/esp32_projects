/**
 * @file base_mvc.h
 * @brief Base MVC framework for waveshare ESP32-P4-3.4 circle screen board Application.
 * @author dingjun
 * @date 2025-07-20
 */

#ifndef _BASE_MVC_H_
#define _BASE_MVC_H_

#include "message_center.h"

//namespace esp32_ws {

class BaseModel {
public:
    virtual void update(const stMessage& msg) = 0; // Update model state
    virtual ~BaseModel() = default;
};

class BaseView {
public:
    virtual void create(lv_obj_t * parent) = 0;
    virtual void update() = 0; // Update view based on model state
    virtual void close() = 0; // Clean up view resources
    virtual ~BaseView() = default;
};

class BaseController {
public:
    virtual void handleMessage(const stMessage& msg) = 0; // Handle events and update model/view
    virtual ~BaseController() = default;
};

class MVCComponent {
public:
    BaseModel* model_;
    BaseView* view_;
    BaseController* controller_;
};


//} // end of namespace esp32_ws


#endif // _BASE_MVC_H_
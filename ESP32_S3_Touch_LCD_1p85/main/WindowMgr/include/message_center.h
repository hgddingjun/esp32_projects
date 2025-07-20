/*
 * @file message_center.h
 * @brief Message Center for waveshare ESP32-P4-3.4 circle screen board Application.
 * @author dingjun
 * @date 2025-07-20
 */
#ifndef _MESSAGE_CENTER_H_
#define _MESSAGE_CENTER_H_

#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

//namespace esp32_ws {

//消息定义
enum eMessageType {
    kWindowChange = 0,
    kBTConnect,
    kBTDisconnect,
    kMusicPlay,
    kMusicPause,
    kMusicStop,
    kMusicNext,
    kMusicPrev,
    kMusicVolumeUp,
    kMusicVolumeDown,
    kMusicVolumeMute,
    kMusicVolumeUnmute,
    kVideoPlay,
    kVideoPause,
    kVideoStop,
    kVideoNext,
    kVideoPrev,
    kVideoVolumeUp,
    kVideoVolumeDown,
    kVideoVolumeMute,
    kVideoVolumeUnmute,
    kButtonClick,
    kUpdateHome,

    kMessageTypeMax

};


struct stMessage {
    enum eMessageType type; //消息类型
    void*        data; //消息数据
};

class MessageCenter {
public:
    static void init();
    static bool sendMessage(const stMessage& msg);
    static bool recvMessage(stMessage& msg, TickType_t timeout = portMAX_DELAY);
    virtual ~MessageCenter() = default;

private:
    static QueueHandle_t messageQueue_; //消息队列句柄
    MessageCenter() = default;
    MessageCenter(const MessageCenter&) = delete;
    MessageCenter& operator=(const MessageCenter&) = delete;
};


//} // end of namespace esp32_ws

#endif // _MESSAGE_CENTER_H_
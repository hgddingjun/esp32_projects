/**
 * @file mp3_window.h
 * @brief Base MVC framework for waveshare ESP32-P4-3.4 circle screen board Application.
 * @author dingjun
 * @date 2025-07-20
 */

#ifndef _MP3_WINDOW_H_
#define _MP3_WINDOW_H_

#include "base_mvc.h"

//namespace esp32_ws {

class Mp3Model : public BaseModel {
public:
    bool isPlaying() const {
        // Return whether the MP3 player is currently playing
        return playing_;
    }
    void update(const stMessage& msg) override {
        // Handle messages specific to the MP3 model
        // For example, update playback state based on the message type
        switch (msg.type) {
            case kMusicPlay:
                // Start playback
                break;
            case kMusicPause:
                // Pause playback
                break;
            case kMusicStop:
                // Stop playback
                break;
            case kMusicNext:
                // Play next track
                break;
            case kMusicPrev:
                // Play previous track
                break;
            default:
                break;
        }
    }
private:
    bool playing_ = false; // Current playback state
};

class Mp3View : public BaseView {
public:
    void create(lv_obj_t * parent) override {
        // Create the MP3 player view
        // For example, create buttons for play, pause, next, previous
    }

    void update() override {
        // Update the MP3 view based on the model state
    }

    void close() override {
        // Clean up resources used by the MP3 view
    }

private:
    lv_obj_t * btnPlay_;
    lv_obj_t * btnPause_;
    lv_obj_t * btnNext_;
    lv_obj_t * btnPrev_;
    static void handleMp3ButtonClick(lv_event_t * e) {
        // Handle button click events
        lv_obj_t * btn = lv_event_get_target(e);
        stMessage msg;
        msg.type = kButtonClick;
        msg.data = btn; // Pass the button object as data
        MessageCenter::sendMessage(msg);
    }
};

MVCComponent* CreateMp3MVC();

//} // end of namespace esp32_ws

#endif // _MP3_WINDOW_H_
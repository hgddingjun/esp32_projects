#include "AudioPlayer.hpp"
#include "esp_log.h"
//#include "driver/i2s.h"
#include "driver/i2s_std.h" 

static const char* TAG = "AudioPlayer";

CAudioPlayer::CAudioPlayer() {
    //初始化成员变量
    ESP_LOGI(TAG,"ctor:CAudioPlayer::CAudioPlayer...");
}

CAudioPlayer::~CAudioPlayer() {
    ESP_LOGI(TAG,"dtor:CAudioPlayer::~CAudioPlayer...");
}

bool CAudioPlayer::initialize() {
    return 0;
}

void CAudioPlayer::play(const std::string& url) {
    ESP_LOGI(TAG,"Playing:%s", url.c_str());

}

void CAudioPlayer::pause() {

}

void CAudioPlayer::stop() {

}

void CAudioPlayer::setVolume(uint8_t vol) {

}

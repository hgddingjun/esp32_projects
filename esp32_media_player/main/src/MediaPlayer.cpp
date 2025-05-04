#include "MediaPlayer.hpp"
#include "esp_log.h"

static const char* TAG = "MediaPlayer";

CMediaPlayer::CMediaPlayer() {
    ESP_LOGI(TAG,"ctor:CMediaPlayer::CMediaPlayer...");
}

CMediaPlayer::~CMediaPlayer() {
    ESP_LOGI(TAG,"dtor:CMediaPlayer::~CMediaPlayer...");
}

void CMediaPlayer::initialize() {

}

void CMediaPlayer::play(const std::string& url) {
    ESP_LOGI(TAG, "Playing:%s", url.c_str());
}

void CMediaPlayer::pause() {

}

void CMediaPlayer::stop() {

}

void CMediaPlayer::update() {

}
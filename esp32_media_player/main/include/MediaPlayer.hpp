#pragma once

#include <iostream>
#include <memory>
#include <string>
#include "AudioPlayer.hpp"

class CMediaPlayer {
public:
    CMediaPlayer();
    virtual ~CMediaPlayer();
    void initialize();
    void play(const std::string& url);
    void pause();
    void stop();
    void update();

private:
    std::unique_ptr<CAudioPlayer> m_AudioPlayer;
};
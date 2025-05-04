#pragma once

#include <iostream>
#include <string>

//enum eDecoderState {eOkay,eError};

class CAudioPlayer {
public:
    CAudioPlayer();
    virtual ~CAudioPlayer();

    bool initialize();
    void play(const std::string& url);
    void pause();
    void stop();
    void setVolume(uint8_t vol);

private:
    //enum eDecoderState m_State;
    //I2S Configure
    //buffer...

};
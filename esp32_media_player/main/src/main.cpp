#include "MediaPlayer.hpp"
#include "SdCard.hpp"
#include "esp_log.h"

static const char* TAG = "Main";
extern "C" void app_main() {
    CSdCard& sd = CSdCard::getInstance();
    CSdCard& sd2 = CSdCard::getInstance();
    assert(&sd == &sd2);

    ESP_LOGI(TAG, "Mount SD card.");
    sd.initialize();
    ESP_LOGI(TAG, "Scan SD card...");
    sd.getAllFiles("/sdcard");
}
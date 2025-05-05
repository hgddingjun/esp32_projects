#include "SdCard.hpp"

#include "esp_log.h"

#include <iostream>
#include <string>

#define MOUNT_POINT "/sdcard"

static const char* SDTAG = "SdCard";

void CSdCard::initialize() {
    sdmmc_host_t host = SDSPI_HOST_DEFAULT();
    spi_bus_config_t bus_cfg = {
        .mosi_io_num = SD_MOSI_PIN,     // GlobalConfig.h 中定义
        .miso_io_num = SD_MISO_PIN,     // GlobalConfig.h 中定义
        .sclk_io_num = SD_CLK_PIN,      // GlobalConfig.h 中定义
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .data4_io_num = -1,
        .data5_io_num = -1,
        .data6_io_num = -1,
        .data7_io_num = -1,
        .max_transfer_sz = 400000,
        .flags = 0,                  // 显式初始化为0
        .isr_cpu_id = ESP_INTR_CPU_AFFINITY_AUTO,  // 使用ESP-IDF提供的默认值
        .intr_flags = 0              // 显式初始化为0
    };
    esp_err_t ret = spi_bus_initialize((spi_host_device_t)host.slot, &bus_cfg, SPI_DMA_CH_AUTO);
    if (ret != ESP_OK) {
        ESP_LOGE(SDTAG, "Failed to initialize bus.");
        return;
    }else{
        ESP_LOGI(SDTAG, "Succeeded to initialize bus.");
    }

    const char mount_point[] = MOUNT_POINT;
    sdspi_device_config_t slot_config = SDSPI_DEVICE_CONFIG_DEFAULT();
    slot_config.gpio_cs = SD_CS_PIN;  // CS 引脚，在 GlobalConfig.h 中已定义
    slot_config.host_id = (spi_host_device_t)host.slot;
    sdmmc_card_t *card;
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = true,
        .max_files = 5,
        .allocation_unit_size = 16 * 1024,
        .disk_status_check_enable = false
    };

    ESP_LOGI(SDTAG, "Mounting filesystem...");
    ret = esp_vfs_fat_sdspi_mount(mount_point, &host, &slot_config, &mount_config, &card);
    if (ret != ESP_OK) {
        if (ret == ESP_FAIL) {
            ESP_LOGE(SDTAG, "Failed to mount filesystem. "
                    "If you want the card to be formatted, set the CONFIG_EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
        } else {
            ESP_LOGE(SDTAG, "Failed to initialize the card (%s). "
                    "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret));
        }
        return;
    }
    ESP_LOGI(SDTAG, "Filesystem mounted");

    // Card has been initialized, print its properties
    sdmmc_card_print_info(stdout, card);
}

void CSdCard::getAllFiles(const char* path) {
    // 打开目录
    DIR* dir = opendir(path);
    if (dir == NULL)
    {
        ESP_LOGE(SDTAG,"Failed to open dir:%s", path);
        return;
    }

    // 遍历目录下的文件
    struct dirent *entry;
    struct stat statbuf;
    while ((entry = readdir(dir)) != NULL) 
    {
        // 获取 entry 的完整路径
        std::string file_path = path ? path : "";
        file_path.append("/");
        file_path.append(entry->d_name);
        // 输出路径
        ESP_LOGI(SDTAG,"Output path:%s", file_path.c_str());

        // 获取 entry 的属性
        if (stat(file_path.c_str(), &statbuf) == -1)
        {
            continue;
        }
        // entry 是文件夹       
        if (S_ISDIR(statbuf.st_mode)) {
            // 递归遍历子文件夹
            getAllFiles(file_path.c_str()); 
        }
    }
    // 关闭目录
    closedir(dir);
}
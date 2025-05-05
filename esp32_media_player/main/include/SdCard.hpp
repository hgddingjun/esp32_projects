#pragma once

#include <string.h>
#include <sys/unistd.h>
#include <sys/stat.h>
#include <sys/dirent.h>

#include "esp_vfs_fat.h"
#include "sdmmc_cmd.h"

#include "GlobalConfig.h"

class CSdCard {
public:
    GET_INSTANCE(CSdCard);
    NONCOPY_CONSTRUCTOR(CSdCard);   // 禁止拷贝构造
    NONCOPY_ASSIGNMENT(CSdCard);    // 禁止拷贝赋值
    NONMOVE_CONSTRUCTOR(CSdCard);   // 禁止移动构造
    NONMOVE_ASSIGNMENT(CSdCard);    // 禁止移动赋值

    void initialize();
    void getAllFiles(const char* path);

private:
    CSdCard() {}
    ~CSdCard() {}
};
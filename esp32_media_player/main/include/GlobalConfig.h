#ifndef _GLOBAL_CONFIG_H_
#define _GLOBAL_CONFIG_H_

//sdcard
#define SD_CS_PIN               GPIO_NUM_12
#define SD_CLK_PIN              GPIO_NUM_14
#define SD_MOSI_PIN             GPIO_NUM_15
#define SD_MISO_PIN             GPIO_NUM_2


#define GET_INSTANCE(ClassName) \
    static ClassName& getInstance() { \
        static ClassName instance; \
        return instance; \
    }

#define NONCOPY_CONSTRUCTOR(ClassName) \
    ClassName(const ClassName&) = delete

#define NONCOPY_ASSIGNMENT(ClassName) \
    ClassName& operator=(const ClassName&) = delete

#define NONMOVE_CONSTRUCTOR(ClassName) \
    ClassName(ClassName&&) = delete

#define NONMOVE_ASSIGNMENT(ClassName) \
    ClassName& operator=(ClassName&&) = delete





#endif/* _GLOBAL_CONFIG_H_ */
set(COMPONENT_SRCDIRS "src" "../main/src")
set(COMPONENT_ADD_INCLUDEDIRS "include" "../main/include")

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 源文件列表
file(GLOB_RECURSE SOURCES "src/*.cpp")

# 注册组件
idf_component_register(SRCS ${SOURCES}
                    INCLUDE_DIRS "include"
                    REQUIRES esp_http_client esp_https_ota fatfs spiffs sdmmc)
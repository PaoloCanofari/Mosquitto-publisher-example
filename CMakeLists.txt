cmake_minimum_required(VERSION 3.14)
project(Mosquitto-publisher-example)

set(CMAKE_PREFIX_PATH /opt/qt5pi/sysroot/usr/local/qt5pi/lib/cmake)

link_directories(
        /usr/lib/x86_64-linux-gnu/
)

include_directories(
        /usr/include
)
set(CMAKE_CXX_STANDARD 17)

add_executable(Mosquitto-publisher-example main.cpp mqtt_wrapper/mqtt_wrapper.cpp mqtt_wrapper/mqtt_wrapper.h)

target_link_libraries(Mosquitto-publisher-example mosquitto)
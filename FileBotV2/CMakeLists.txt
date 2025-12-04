cmake_minimum_required(VERSION 3.16)

project(FileBotV2 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Gui Qml Quick)

add_executable(FileBotV2
    src/main.cpp
)

target_link_libraries(FileBotV2
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

cmake_minimum_required(VERSION 3.16)
project(FilterGlass)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
qt_add_resources(APP_RESOURCES resources/resources.qrc)
file(GLOB SOURCES "src/*.cpp")
add_executable(FilterGlass
    ${SOURCES}
    ${APP_RESOURCES}
)

target_link_libraries(FilterGlass PRIVATE Qt6::Widgets)
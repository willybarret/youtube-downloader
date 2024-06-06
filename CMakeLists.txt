cmake_minimum_required(VERSION 3.25)
project(YouTube-Downloader)

set(CMAKE_CXX_STANDARD 14)

if (WIN32)
    set(CMAKE_PREFIX_PATH "C:/Qt/6.7.1/mingw_64/lib/cmake" CACHE PATH "Path to Qt6 on Windows")
endif ()

include_directories(src)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES "src/*.cpp" "src/*.h")

add_executable(YouTube-Downloader ${SOURCES})

if (WIN32)
    set_target_properties(YouTube-Downloader PROPERTIES WIN32_EXECUTABLE TRUE)
endif ()

target_link_libraries(YouTube-Downloader
        Qt6::Core
        Qt6::Widgets)

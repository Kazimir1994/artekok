cmake_minimum_required(VERSION 3.5)
project(TaskBoard)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(taskboard
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.h
)

target_link_libraries(taskboard Qt5::Widgets)

cmake_minimum_required(VERSION 3.5)

project(brightness_of_the_picture VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
)

file(
    COPY "${CMAKE_CURRENT_SOURCE_DIR}/img"
    DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)

add_executable(brightness_of_the_picture
    ${PROJECT_SOURCES}
)

target_link_libraries(brightness_of_the_picture PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

install(TARGETS brightness_of_the_picture
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(brightness_of_the_picture)
endif()

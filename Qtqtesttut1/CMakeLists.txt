cmake_minimum_required(VERSION 3.5)

project(Qtqtesttut1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing(true)
# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt5Test REQUIRED)
find_package(Gtest REQUIRED)

set(TS_FILES Qtqtesttut1_en_AT.ts)

if(ANDROID)
  add_library(Qtqtesttut1 SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${TS_FILES}
  )
else()
  add_executable(Qtqtesttut1
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    udemytut1.cpp
    udemytut1.h
    ${TS_FILES}
  )
endif()

target_link_libraries(Qtqtesttut1 PRIVATE Qt5::Widgets)
target_link_libraries(Qtqtesttut1 PRIVATE  gtest gmock)

qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
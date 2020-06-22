cmake_minimum_required(VERSION 3.5)

project(BasketballStatistics LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


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

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

set(RESOURCE_FILES qml.qrc)
set(SOURCE_FILES
    src/main.cpp
    src/model/shot.cpp
    src/model/shot.h
    src/model/player.cpp
    src/model/player.h
    src/model/playerlistmodel.cpp
    src/model/playerlistmodel.h
    src/mainmodel.h
    src/mainmodel.cpp
    src/model/team.cpp
    src/model/team.h
    src/model/statistics.h
    src/model/statistics.cpp
    src/model/playerstatistics.cpp
    src/model/playerstatistics.h
    src/model/teamstatistics.cpp
    src/model/teamstatistics.h
    )

if(ANDROID)
    add_library(BasketballStatistics SHARED
      ${SOURCE_FILES}
      ${RESOURCE_FILES}
    )
else()
    add_executable(BasketballStatistics
        ${SOURCE_FILES}
        ${RESOURCE_FILES}
    )
endif()

target_compile_definitions(BasketballStatistics
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(BasketballStatistics
  PRIVATE Qt5::Core Qt5::Quick)

QT += quick

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/main.cpp \
    	src/model/shot.cpp \
    	src/model/player.cpp \
    	src/model/playerlistmodel.cpp \
    	src/mainmodel.cpp \
    	src/model/team.cpp \
    	src/model/statistics.cpp \
    	src/model/playerstatistics.cpp \
    	src/model/teamstatistics.cpp \

HEADERS += \
    	src/model/shot.h \
    	src/model/player.h \
    	src/mainmodel.h \
    	src/model/team.h \
    	src/model/statistics.h \
    	src/model/playerstatistics.h \
    	src/model/teamstatistics.h \
        src/model/basemodel.h \
        src/model/playerlistmodel.h \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

CONFIG += debug_and_release

INCLUDEPATH += $$PWD/include/public
INCLUDEPATH += $$PWD/include/xilou_public
CONFIG(debug, debug|release){
LIBS += -L$$PWD/out/debug -lpdfium.dll
DESTDIR = $$PWD/out/debug
}else{
LIBS += -L$$PWD/out/release -lpdfium.dll
DESTDIR = $$PWD/out/release
}


#-------------------------------------------------
#
# Project created by QtCreator 2018-08-09T16:43:05
#
#-------------------------------------------------

QT       += multimedia multimediawidgets

QT       -= gui

TARGET = CssMultimedia
TEMPLATE = lib

INCLUDEPATH += ../CssCore
DEPENDPATH += ../CssCore

DEFINES += CSSMULTIMEDIA_LIBRARY

CONFIG(debug, debug|release) {
    TARGET = CssMultimediad
}
CONFIG(release, debug|release) {
    TARGET = CssMultimedia
}

win32 {
    MOC_DIR = tmp-win32
    UI_DIR = tmp-win32
    UI_HEADERS_DIR = tmp-win32
    UI_SOURCES_DIR = tmp-win32
    OBJECTS_DIR = tmp-win32
    RCC_DIR = tmp-win32
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cssmultimedia.cpp

HEADERS += \
        cssmultimedia.h \
        cssmultimedia_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

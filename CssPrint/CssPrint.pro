#-------------------------------------------------
#
# Project created by QtCreator 2018-06-14T16:05:51
#
#-------------------------------------------------

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

TARGET = CssPrint
TEMPLATE = lib

INCLUDEPATH += ../CssCore
DEPENDPATH += ../CssCore

DEFINES += CSSPRINT_LIBRARY


CONFIG(debug, debug|release) {
    TARGET = CssPrintd
}
CONFIG(release, debug|release) {
    TARGET = CssPrint
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
        cssprint.cpp

HEADERS += \
        cssprint.h \
        cssprint_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}

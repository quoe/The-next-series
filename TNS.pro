#-------------------------------------------------
#
# Project created by QtCreator 2012-10-27T15:41:50
#
#-------------------------------------------------

QT       += core gui

TARGET = TNS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        serials.cpp

TRANSLATIONS += tns_ru.ts

HEADERS  += mainwindow.h \
    serials.h

FORMS    += mainwindow.ui

RESOURCES += \
    resourse.qrc

win32 {
    RC_FILE += file.rc
    OTHER_FILES += file.rc
}

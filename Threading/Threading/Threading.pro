#-------------------------------------------------
#
# Project created by QtCreator 2011-04-14T20:35:49
#
#-------------------------------------------------

QT       += core gui

TARGET = Threading
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    input_thread.cpp \
    output_thread.cpp \
    dialog_com.cpp \
    proto_uso.cpp \
    connect_dialog.cpp \
    dev_info.cpp


HEADERS  += mainwindow.h \
    input_thread.h \
    output_thread.h \
    dialog_com.h \
    proto_uso.h \
    connect_dialog.h \
    dev_info.h

FORMS    += mainwindow.ui \
    dialog_com.ui \
    connect_dialog.ui \
    dev_info.ui

INCLUDEPATH += ./serial_src/qserialdevice
INCLUDEPATH += ./serial_src/qserialdeviceenumerator

QMAKE_LIBDIR += ./libs
LIBS += -lqserialdevice\
        -lqserialdeviceenumerator

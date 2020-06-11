#-------------------------------------------------
#
# Project created by QtCreator 2020-06-02T15:27:03
#
#-------------------------------------------------

QT       += widgets

TARGET = VSCodeMemory
TEMPLATE = lib

DEFINES += VSCODEMEMORY_LIBRARY

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
    hl_md5.cpp \
    hl_md5wrapper.cpp \
        vscodememory.cpp \
    VSPtr.cpp \
    Node.cpp \
    List.cpp \
    json.cpp \
    heap.cpp \
    GarbageCollector.cpp \
    client.cpp

HEADERS += \
        hl_md5wrapper.h \
        vscodememory.h \
        vscodememory_global.h \ 
    VSPtr.h \
    Node.h \
    List.h \
    json.h \
    heap.h \
    GarbageCollector.h \
    client.h \
    hl_types.h \
    hl_md5.h \
    hl_hashwrapper.h \
    hl_exception.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}



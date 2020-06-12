QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TEMPLATE = lib
DEFINES += VSCODEMEMORY_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    GarbageCollector.cpp \
    List.cpp \
    Node.cpp \
    TList.cpp \
    TNode.cpp \
    VSPtr.cpp \
    client.cpp \
    heap.cpp \
    hl_md5.cpp \
    hl_md5wrapper.cpp \
    json.cpp \
    vscodememory.cpp

HEADERS += \
    GarbageCollector.h \
    List.h \
    Node.h \
    TList.h \
    TNode.h \
    VSCodeMemory_global.h \
    VSPtr.h \
    client.h \
    heap.h \
    hl_exception.h \
    hl_hashwrapper.h \
    hl_md5.h \
    hl_md5wrapper.h \
    hl_types.h \
    json.h \
    vscodememory.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target


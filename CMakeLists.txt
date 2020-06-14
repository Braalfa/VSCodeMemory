cmake_minimum_required(VERSION 3.16)
project(VSCodeMemory)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(VSCodeMemory
        client.cpp
        client.h
        GarbageCollector.cpp
        GarbageCollector.h
        heap.cpp
        heap.h
        hl_exception.h
        hl_hashwrapper.h
        hl_md5.cpp
        hl_md5.h
        hl_md5wrapper.cpp
        hl_md5wrapper.h
        hl_types.h
        json.cpp
        json.h
        List.cpp
        List.h
        main.cpp
        Node.cpp
        Node.h
        Reader.cpp
        Reader.h
        TList.cpp
        TList.h
        TNode.cpp
        TNode.h
        VSPtr.cpp
        VSPtr.h)

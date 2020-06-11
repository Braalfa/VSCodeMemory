cmake_minimum_required(VERSION 3.16)
project(VSCodeMemoryLib)

set(CMAKE_CXX_STANDARD 14)

add_executable(VSCodeMemoryLib main.cpp Client.h Client.cpp Heap.h Heap.cpp hl_md5wrapper.cpp
        hl_md5wrapper.h hl_md5.cpp hl_md5.h hl_hashwrapper.h hl_exception.h hl_types.h json.cpp json.h List.h List.cpp
        Node.h Node.cpp  GarbageCollector.h GarbageCollector.cpp VSPtr.h VSPtr.cpp TNode.h TNode.cpp TList.h TList.cpp)
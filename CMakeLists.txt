cmake_minimum_required(VERSION 3.20)
project(MTA_FaceBook)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MTA_FaceBook
        main.cpp
        FaceBook.cpp
        FaceBook.h
        FanPage.cpp
        FanPage.h
        Member.cpp
        Member.h
        Status.cpp
        Status.h
        Functions.cpp
        Functions.h
        )

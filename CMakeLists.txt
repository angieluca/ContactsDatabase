cmake_minimum_required(VERSION 3.27)
project(ContactsDatabase)

set(CMAKE_CXX_STANDARD 17)

add_executable(ContactsDatabase main.cpp
        ContactBook.h
        ContactBook.cpp)

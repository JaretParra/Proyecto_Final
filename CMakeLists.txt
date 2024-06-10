cmake_minimum_required(VERSION 3.5)

project(Tienda_Parra)

file(GLOB SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "Headers/*.h")

add_executable(Tienda_Parra main.cpp ${SOURCES} ${HEADERS})
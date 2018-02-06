cmake_minimum_required(VERSION 3.7)
project(Supermercado_Cola)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Cola.h Cola.cpp Clientes.cpp Clientes.h)
add_executable(Supermercado_Cola ${SOURCE_FILES})
cmake_minimum_required(VERSION 3.26)
project(Proyecto C)

set(CMAKE_C_STANDARD 23)

add_executable(Proyecto src/main.c)

configure_file(resources/productos.txt ${CMAKE_CURRENT_BINARY_DIR}/productos.txt COPYONLY)

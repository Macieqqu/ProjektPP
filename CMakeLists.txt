cmake_minimum_required(VERSION 4.1)
project(ProjektPP C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjektPP main.c
        common.h
        list.h
        list.c
        ui.h
        ui.c
        file_util.h
        file_util.c)

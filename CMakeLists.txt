cmake_minimum_required(VERSION 3.26)
project(CDataframe_tacca_tran C)

set(CMAKE_C_STANDARD 11)

add_executable(CDataframe_tacca_tran
        main.c
        column.h
        column.c
        CDataframe.c
        CDataframe.h
        sort.c
        sort.h)

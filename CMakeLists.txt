cmake_minimum_required(VERSION 3.5)

project(test_circularbuffer LANGUAGES C)

add_executable(test_circularbuffer main.c CircularBuffer.c)

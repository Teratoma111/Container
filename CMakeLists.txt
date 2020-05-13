cmake_minimum_required(VERSION 3.10)

project(container)
file(GLOB SOURCES "*.cpp")

add_executable(container ${SOURCES})
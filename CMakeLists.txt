cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

project(ring_buffer)
add_executable(
	ringBuffer
	src/main.cpp
	src/ringBuffer.h
	src/UnitTests.cpp
	)

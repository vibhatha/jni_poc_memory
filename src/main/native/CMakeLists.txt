cmake_minimum_required(VERSION 3.10)
project(NativeLib)
find_package(JNI REQUIRED)
include_directories(src/main/native/include)
add_library(NativeLib SHARED NativeLib.cpp Person.cpp Main.cpp Person_JNI.cpp)
target_include_directories(NativeLib PUBLIC ${JNI_INCLUDE_DIRS})

add_executable(main Main.cpp Person.cpp)

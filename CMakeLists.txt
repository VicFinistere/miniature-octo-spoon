cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)
project(SDLGame)

include(.conan/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB SRC_FILES src/*.cpp)
add_executable(SDLGame ${SRC_FILES})

file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

target_link_libraries(SDLGame ${CONAN_LIBS})
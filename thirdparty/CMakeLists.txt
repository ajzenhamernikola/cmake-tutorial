cmake_minimum_required(VERSION 2.8)
project(stb_image)

include_directories("include/")

set(STB_INCLUDES include/stb_image.h 
                 include/stb_image_write.h)

set(STB_SOURCES source/stb_image.cpp 
                source/stb_image_write.cpp)

add_library(${PROJECT_NAME} ${STB_SOURCES})

install (TARGETS ${PROJECT_NAME} DESTINATION bin)

cmake_minimum_required (VERSION 2.8)
project(app)

include_directories("thirdparty/include/")
add_subdirectory("thirdparty/")

add_executable(${PROJECT_NAME} "src/app.cpp")
target_link_libraries(${PROJECT_NAME} stb_image)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

install (TARGETS ${PROJECT_NAME} DESTINATION bin)
install (FILES "resources/leaves.jpeg" DESTINATION bin)

cmake_minimum_required(VERSION "3.19")
set(MAIN_FILE Main.cpp)

project("Eb")
add_executable("${PROJECT_NAME}" "${MAIN_FILE}")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "${MAIN_FILE}" DESTINATION src)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
target_link_libraries("${PROJECT_NAME}" ${OPENGL_LIBRARIES})
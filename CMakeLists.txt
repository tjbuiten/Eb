cmake_minimum_required(VERSION "3.19")
set(MAIN_FILE Main.cpp)
set(SOURCE_DIRECTORY ./source/domainObjects)

project("Eb")
add_executable(
    "${PROJECT_NAME}"
    "${MAIN_FILE}"
    source/domainObjects/Line.cpp
    source/domainObjects/Pixel.cpp
    source/domainObjects/Square.cpp
    source/domainObjects/ThreeDSquare.cpp
)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "${MAIN_FILE}" DESTINATION src)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(
    source/domainObjects
)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries("${PROJECT_NAME}" ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
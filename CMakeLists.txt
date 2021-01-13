cmake_minimum_required(VERSION "3.19")
set(MAIN_FILE Main.cpp)
set(SOURCE_DIRECTORY ./src)

project("Eb")
add_executable(
    "${PROJECT_NAME}"
    "${MAIN_FILE}"
    src/Includes/Glut.hpp
    src/Structures/Vector2.hpp
    src/Output/Managers/Headers/ScreenManager.hpp
    src/Output/Managers/Source/ScreenManager.cpp
    src/Output/Objects/Headers/Screen.hpp
    src/Output/Objects/Source/Screen.cpp
    src/Input/Managers/Headers/InputManager.hpp
    src/Input/Managers/Source/InputManager.cpp
)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "${MAIN_FILE}" DESTINATION src)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)

include_directories(
    src/Includes/
    src/Structures/
    src/Output/Managers/Headers/
    src/Output/Managers/Source/
    src/Output/Objects/Headers/
    src/Output/Objects/Source/
    src/Input/Managers/Headers/
    src/Input/Managers/Source/
)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries("${PROJECT_NAME}" ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} Boost::thread )
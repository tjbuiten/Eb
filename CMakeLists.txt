cmake_minimum_required(VERSION "3.19")
set (CMAKE_CXX_STANDARD 11)
set(MAIN_FILE Main.cpp)
set(SOURCE_DIRECTORY ./src)

project("Eb")
add_executable(
    "${PROJECT_NAME}"
    "${MAIN_FILE}"
    src/Includes/Glut.hpp
    src/Structures/Vector2.hpp
    src/Input/EventHandlers/Headers/InputEventHandler.hpp
    src/Input/EventHandlers/Headers/CreateScreenEventHandler.hpp
    src/Input/EventHandlers/Source/CreateScreenEventHandler.cpp
    src/Input/Headers/InputEventBus.hpp
    src/Input/Headers/InputEventMap.hpp
    src/Input/Headers/InputEvents.hpp
    src/Input/Managers/Headers/InputManager.hpp
    src/Input/Managers/Source/InputManager.cpp
    src/Input/Source/InputEventBus.cpp
    src/Input/Source/InputEventMap.cpp
    src/Output/Managers/Headers/ScreenManager.hpp
    src/Output/Managers/Source/ScreenManager.cpp
    src/Output/Objects/Headers/Screen.hpp
    src/Output/Objects/Source/Screen.cpp
    src/Structures/Vector2.hpp
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
    src/Input/Headers/
    src/Input/Source/
    src/Input/EventHandlers/Headers/
    src/Input/EventHandlers/Source/
    src/Input/Managers/Headers/
    src/Input/Managers/Source/
    src/Output/Managers/Headers/
    src/Output/Managers/Source/
    src/Output/Objects/Headers/
    src/Output/Objects/Source/
    src/Structures/
)
include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

target_link_libraries("${PROJECT_NAME}" ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} Boost::thread )
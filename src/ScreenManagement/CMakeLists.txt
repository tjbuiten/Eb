find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_library(ScreenManagement
    STATIC
    screen.cc
    display_manager.cc
)

target_include_directories(ScreenManagement
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(ScreenManagement
    PUBLIC
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARY}
    Events
)
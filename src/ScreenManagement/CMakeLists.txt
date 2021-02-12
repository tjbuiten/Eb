add_library(ScreenManagement
    STATIC
    screen.cc
)

target_include_directories(ScreenManagement
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
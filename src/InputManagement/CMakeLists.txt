add_library(InputManagement
    STATIC
    commands.cc
    inputmanager.cc
)

target_include_directories(InputManagement
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(InputManagement
    PUBLIC
    Events
)
add_library(Events
    STATIC
    addscreen_event.cc
    eventbus.cc
    addscreen_workstation.cc
    events_assembly_line.cc
)

target_include_directories(Events
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
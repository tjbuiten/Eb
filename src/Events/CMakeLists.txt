add_library(Events
    STATIC
    addscreen_event.cc
    eventbus.cc
    eventfactory.cc
    addscreen_eventassembler.cc
)

target_include_directories(Events
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
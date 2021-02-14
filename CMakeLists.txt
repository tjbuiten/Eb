cmake_minimum_required(VERSION "3.19")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(MAIN_FILE main.cpp)

project(EB
    VERSION 1.0
    DESCRIPTION "EventBased drawing library"
    LANGUAGES CXX)


add_executable(
    ${PROJECT_NAME}
    ${MAIN_FILE}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES ${MAIN_FILE} DESTINATION src)

add_subdirectory(./src)

target_link_libraries(${PROJECT_NAME} PRIVATE ScreenManagement)
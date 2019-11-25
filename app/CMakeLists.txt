add_executable(shell-app main.cpp pidController.cpp generalPidController.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

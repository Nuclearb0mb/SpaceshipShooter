cmake_minimum_required(VERSION 3.0.0)
project(SpaceshipShooter VERSION 0.1.0)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

add_executable(SpaceshipShooter ${SOURCES})

find_package(glm CONFIG REQUIRED)
    target_link_libraries(SpaceshipShooter PRIVATE glm::glm)


target_link_libraries(SpaceshipShooter PRIVATE sfml-graphics)
target_compile_features(SpaceshipShooter PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET SpaceshipShooter POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:SpaceshipShooter> $<TARGET_FILE_DIR:SpaceshipShooter> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS SpaceshipShooter)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

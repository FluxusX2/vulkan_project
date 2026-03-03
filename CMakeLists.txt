cmake_minimum_required(VERSION 3.20)
project(vulkan_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find Vulkan
find_package(Vulkan REQUIRED)

#find SDL3
include(FetchContent)
FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG main)
FetchContent_MakeAvailable(SDL3)

add_executable(${PROJECT_NAME} src/main.cpp)

# 3. Verknüpfung der Bibliotheken
target_link_libraries(${PROJECT_NAME} PRIVATE
        Vulkan::Vulkan
        SDL3::SDL3
)

# Automatisch die DLLs ins Build-Verzeichniss kopieren
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:SDL3::SDL3-shared>
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

# Spezielle Einstellungen für macOS (MoltenVK)
if(APPLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE VK_USE_PLATFORM_METAL_EXT)
endif()
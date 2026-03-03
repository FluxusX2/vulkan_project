cmake_minimum_required(VERSION 3.20)
project(vulkan_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#find Vulkan
find_package(Vulkan REQUIRED)

#find SDL3
# On Windows/vcpkg or macOS/brew:
find_package(SDL3 REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

# 3. Verknüpfung der Bibliotheken
target_link_libraries(${PROJECT_NAME} PRIVATE
        Vulkan::Vulkan
        SDL3::SDL3
)

# Spezielle Einstellungen für macOS (MoltenVK)
if(APPLE)
    target_compile_definitions(${PROJECT_NAME} PRIVATE VK_USE_PLATFORM_METAL_EXT)
endif()
//
// Created by Mael Brodkorb on 03.03.26.
//

#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <vulkan/vulkan.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    // SDL initialisieren
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL konnte nicht initialisiert werden: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Fenster mit Vulkan-Support erstellen
    SDL_Window* window = SDL_CreateWindow(
        "Vulkan + SDL3 Tutorial",
        800, 800,
        SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        std::cerr << "Fenster konnte nicht erstellt werden: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    // Vulkan Instanz Check
    uint32_t extensionCount = 0;
    const char* const* extensions = SDL_Vulkan_GetInstanceExtensions(&extensionCount);

    std::cout << "Benötigte Vulkan Extensions für SDL3:" << std::endl;
    for (uint32_t i = 0; i < extensionCount; i++) {
        std::cout << "- " << extensions[i] << std::endl;
    }

    // Main Loop Dummy
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
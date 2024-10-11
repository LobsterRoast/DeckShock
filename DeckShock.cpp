#include <SDL2/SDL.h>
#include <bluetooth/bluetooth.h>
#include <iostream>

int main() {
    bool quit = false;
    SDL_Event e;
    SDL_Window* window = SDL_CreateWindow("SDL2 Keyboard Input",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);

    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    while(quit == false) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        int buttonsPressedArrayLength;
        const uint8_t *pressedButtons = SDL_GetKeyboardState(&buttonsPressedArrayLength);
        for (int i = 0; i < buttonsPressedArrayLength; i++) {
            if (pressedButtons[i]) std::cout << (SDL_Scancode)i << " ";
        }
        std::cout << std::endl;
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}
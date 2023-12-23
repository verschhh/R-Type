#include "Window.hpp"

Window::Window() {
    Window(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_POSWINDOWX, DEFAULT_POSWINDOWY,DEFAULT_TITLE, DEFAULT_FONT);
};

Window::Window(int width, int height, int posWindowX, int posWindowY, std::string title, std::string fontPath) {
    _width = width;
    _height = height;
    _posWindowX = posWindowX;
    _posWindowY = posWindowY;

    _title = title;
    _fontPath = fontPath;
    
    sf::VideoMode(width, height);
}

Window::Window(std::string fontPath, bool isFullScreen) {
    if (isFullScreen) {
        //to-do: create a fullscreen window
    } else {
        Window(DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_POSWINDOWX, DEFAULT_POSWINDOWY,DEFAULT_TITLE, fontPath);
    }
}

void Window::ToggleFullscreen() {
    _isFullScreen = !_isFullScreen;

    //to-do:  change window item position and size to fullscreen ones - DOES NOT DISPLAY
}

void Window::ResizeWindow(int newWidth, int newHeight) {
    _width = newWidth;
    _height = newHeight;

    //to-do:  change window item position and size to the new sized one ones - DOES NOT DISPLAY
}
void Window::ChangeFont(std::string newFontPath) {
    _fontPath = newFontPath;

    //to-do: create new font, change fonts to the new font, and destroy old font. - DOES NOT DISPLAY
}

void Window::ChangeTitle(std::string newTitle) {
    _title = newTitle;

    //to-do: probably kill the window and spawn a new one
}
std::vector<int> Window::GetMouseposition() {
    return (std::vector<int>(_mouseX, _mouseY));
}

void Window::Update(int delta_t) {
    //to-do: Will display and update all the window elements.
}
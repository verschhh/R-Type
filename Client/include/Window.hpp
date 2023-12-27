/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Custom R-Type Implementation
*/

#ifndef WINDOW
    #define WINDOW

    #include <string>
    #include <SFML/Window.hpp>

    #include "Loopable.hpp"
    #include "Constants.hpp"

class Window : public Loopable {
    public:
        //Constructors
        Window();
        Window(int width, int height, int posWindowX, int posWindowY, std::string title, std::string fontPath);
        Window(std::string fontPath, bool isFullScreen);

        //Destructors
        ~Window();

        // Window Configuration
        void ToggleFullscreen();
        void ResizeWindow(int newWidth, int newHeight);
        void ChangeFont(std::string newFontPath);
        void ChangeTitle(std::string newTitle);
        std::vector<int> GetMouseposition();

        //Display
        void Update(int delta_t);

    private:
        int _width;
        int _height;
        int _mouseX;
        int _mouseY;
        int _posWindowX;
        int _posWindowY;

        bool _isFullScreen;

        std::string _title;
        std::string _backgroundPath;
        std::string _fontPath;
};

#endif /* !Window */

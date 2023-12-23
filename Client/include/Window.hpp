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

    #define DEFAULT_WIDTH 1300
    #define DEFAULT_HEIGHT 700
    #define DEFAULT_TITLE "R-Type"
    #define DEFAULT_POSWINDOWX 200
    #define DEFAULT_POSWINDOWY 200
    #define DEFAULT_FONT "../ressources/Aurabesh.ttf"


class Window {
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

        //Window Loop

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

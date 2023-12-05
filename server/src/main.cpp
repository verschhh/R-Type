/*
** EPITECH PROJECT, 2023
** R-Type
** File description:
** Server main
*/


#ifdef _WIN32
    // Windows-specific code
    #include <windows.h>
#elif __linux__
    // Linux-specific code
    #include <unistd.h>
#endif

#include <iostream>

int main() {
    // Common code
    
    #ifdef _WIN32
        // Windows-specific code
        MessageBox(NULL, "Hello from Windows!", "Platform Message", MB_OK);
    #elif __linux__
        // Linux-specific code
        write(STDOUT_FILENO, "Hello from Linux!\n", 18);
    #endif

    // Common code

    return 0;
}
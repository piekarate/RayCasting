#include "Application.hpp"


int main()
{
    // Create the main window
    Application app;
    
    // Start the game loop
    while (app.isRunning())
    {
        app.update();

        app.render();
    }
}

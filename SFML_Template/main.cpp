#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "GUI.h"
#include "Upgrades.h"



int main()
{

    //sf::RenderWindow window{ {1920, 1080}, "TGUI window with SFML" }; replaced with the code below =)
    sf::RenderWindow window{ sf::VideoMode(1920,1080), "Cookie Clicker" };

    // Creates the texture called t
    sf::Texture t;

    // Loads the texture from the file background.png and checks it it fails to load
    if (!t.loadFromFile("background.png"))
    {
        std::cerr << "ERORR, could not load texture";
    }

    // Creates a sprite that can be used to load the background in the window
    sf::Sprite s(t);
   

    // A Gui Object that works with Sfml window. 
    tgui::GuiSFML gui{ window };

    // Create GUI instance and initialize the GUI
    GUI guiObject;


    if (!guiObject.RunGUI(gui))
    {
        std::cerr << "Failed to initialize GUI." << std::endl;
        return -1;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calls the updategui function from GUI.cpp
        guiObject.updategui();

        // Draw the background before the GUI, so the GUI dosent end up behind the background
        window.draw(s);

        // Draws the gui
        gui.draw();

        // Display the window with all the previous drawn things such as the background, gui
        window.display();
    }
}

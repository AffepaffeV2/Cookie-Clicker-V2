#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "GUI.h"
#include "Upgrades.h"



int main()
{
    sf::RenderWindow window{ {1920, 1080}, "TGUI window with SFML" };

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

        window.clear();
        gui.draw();
        guiObject.updategui();
        window.display();
    }
}

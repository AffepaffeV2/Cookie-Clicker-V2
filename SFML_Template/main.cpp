#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "GUI.h"
#include "Upgrades.h"



int main()
{

    //sf::RenderWindow window{ {1920, 1080}, "TGUI window with SFML" };
    sf::RenderWindow window{ sf::VideoMode(1920,1080), "Cookie Clicker" };

    sf::Texture t;

    if (!t.loadFromFile("background.png"))
    {
        std::cerr << "ERORR, could not load texture";
    }

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

        window.clear();
        guiObject.updategui();
        window.draw(s);
        gui.draw();
        window.display();
    }
}

#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "GUI.h"



//For a easy debugging will show if a file counld not be opened in the console.
bool RunGUI(tgui::GuiBase& gui)
{
    try
    {
        guicreator("Click Me", gui);
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}



//main entry
int main()
{
    sf::RenderWindow window{ {800, 600}, "TGUI window with SFML" };
    
    //A Gui Object that works with Sfml window. 
    tgui::GuiSFML gui{ window };
    
    RunGUI(gui);

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
        window.display();
    }
}
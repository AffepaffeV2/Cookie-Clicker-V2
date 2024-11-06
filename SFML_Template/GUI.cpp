#include "GUI.h"

GUI::GUI() 
{



}

GUI::~GUI()
{



}

//Updates the UI
void GUI::updategui()
{



}

// Renders the UI
void GUI::rendergui()
{



}

void GUI::print_someting(std::string text)
{

        std::cout << text;
}


void GUI::guicreator(std::string ButtonText, std::string PrintText, tgui::GuiBase& gui, std::string size = "50%, 16.67%", std::string position = "25%, 70%")
{
        auto button = tgui::Button::create(ButtonText);
        button->setSize({size});
        button->setPosition({position});
        gui.add(button);
        button->onPress(print_someting, PrintText);
}



#include <iostream>
#include "GUI.h"

GUI::GUI()
{
}

GUI::~GUI()
{
}


void GUI::print_someting(const std::string& text)
{
    std::cout << text;
}

void GUI::clicker(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY)
{

    auto button = tgui::Button::create(ButtonText);

    // Set the size of the label
    button->setSize({ sizeWidth, sizeHeight });

    // Set the position of the label
    button->setPosition({ posX, posY });

    gui.add(button);

    // Button press event: Update cookie count and refresh label
    button->onPress([this, PrintText]() {
        cookies += cpc; // Increment the cookie count

        // Print to console (for debugging)
        print_someting(PrintText);

        // Update the label text with the current cookie count
        if (cookieLabel) {
            cookieLabel->setText("Cookies: " + std::to_string(cookies));
        }
        });
}


void GUI::staticguicreator(tgui::GuiBase& gui, const std::string ButtonText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY)
{
    cookieLabel = tgui::Label::create(ButtonText);

    cookieLabel->setSize({ sizeWidth, sizeHeight });
    cookieLabel->setPosition({ posX, posY });
    cookieLabel->getRenderer()->setTextColor(tgui::Color(255, 255, 255));
    cookieLabel->setTextSize(25);

    gui.add(cookieLabel);
}
// Public function to initialize the GUI
bool GUI::RunGUI(tgui::GuiBase& gui)
{
    try
    {
        clicker(gui, "Click Me", "Button clicked!", "50%, 16.67%", "25%, 70%");
        staticguicreator(gui,"Cookies: 0", "75%", "25%", "0%", "0%");
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}

// Updates the UI
void GUI::updategui()
{

    sf::Time time = cpstimer.getElapsedTime();
    
    if (time.asSeconds() >= 1)
    { 
        std::cout << time.asMilliseconds() << std::endl; // Prints in console everytime it updates used for debugging
        cookies += cps;
        this->cookieLabel->setText("Cookies: " + std::to_string(cookies));
        cpstimer.restart();
        }
 }

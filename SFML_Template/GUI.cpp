#include "GUI.h"

GUI::GUI()
{
}

GUI::~GUI()
{
}

// Updates the UI
void GUI::updategui()
{
}

// Renders the UI
void GUI::rendergui()
{
}

void GUI::print_someting(const std::string& text)
{
    std::cout << text;
}

void GUI::guicreator2(tgui::GuiBase& gui, const std::string& ButtonText, const std::string& PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY)
{
    auto button = tgui::Button::create(ButtonText);

    // Set the size of the label
    button->setSize({ sizeWidth, sizeHeight });

    // Set the position of the label
    button->setPosition({ posX, posY });

    gui.add(button);

    // Controls what will happen when button is pressed
    button->onPress([this, PrintText]() { this->print_someting(PrintText); });
}

void GUI::staticguicreator(tgui::GuiBase& gui, const std::string& ButtonText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY)
{
    auto button = tgui::Button::create(ButtonText);

    // Set the size of the label
    button->setSize({ sizeWidth, sizeHeight });

    // Set the position of the label
    button->setPosition({ posX, posY });

    gui.add(button);
}
// Public function to initialize the GUI
bool GUI::RunGUI(tgui::GuiBase& gui)
{
    try
    {
        guicreator2(gui, "Click Me", "Button clicked!", "50%, 16.67%", "25%, 70%");
        staticguicreator(gui, "Cookies: 0","50%", "16,67%", "70%", "25%");
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}

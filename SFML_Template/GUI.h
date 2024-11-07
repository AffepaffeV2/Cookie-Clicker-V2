#include<iostream>
#include<string>�
#include <TGUI/TGUI.hpp>
#pragma once

class GUI
{
public:
    // Constructor
    GUI();

    // Deconstructor
    ~GUI();

    // Public method to initialize GUI
    bool RunGUI(tgui::GuiBase& gui);

    void updategui();

private:
    // Accept width and height as separate Layout parameters
    void clicker(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth = "50%", tgui::Layout sizeHeight = "16.67%", tgui::Layout posX = "25%", tgui::Layout posY = "70%");

    void staticguicreator(tgui::GuiBase& gui,const std::string ButtonText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY );
 
    void print_someting(const std::string& text);

    int cookies = 0;

    int cpc = 1;

    tgui::Label::Ptr cookieLabel;

};

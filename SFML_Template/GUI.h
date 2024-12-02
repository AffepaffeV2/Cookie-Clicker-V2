#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "Upgrades.h"
#include <vector>
#include <string>
#pragma once

class Upgrades;

class GUI
{
public:
    // Constructor
    GUI();

    // Deconstructor
    ~GUI();

    // Public method to initialize and run the GUI
    bool RunGUI(tgui::GuiBase& gui, Upgrades& upgrades);

    // Updates the GUI elements based on Upgrades class
    void updategui(Upgrades& upgrades);

private:

    tgui::Label::Ptr cpslabel;

    tgui::Label::Ptr upgradeslabel;

    tgui::Label::Ptr cpclabel;

        void cookie_label(tgui::GuiBase & gui, const std::string ButtonText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY);

        void cpc_label(tgui::GuiBase& gui, std::string displaytext, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY);

        void print_someting(const std::string & text);

        void cps_label(tgui::GuiBase & gui, std::string displaytext, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY);

        sf::Clock cpstimer;

    };

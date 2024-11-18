#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#pragma once

class GUI
{
public:
    // Constructor
    GUI();

    // Deconstructor
    ~GUI();

    //Holds a refrance to My label
    tgui::Label::Ptr cookieLabel;

    tgui::Label::Ptr cpslabel;

    // Public method to initialize GUI
    bool RunGUI(tgui::GuiBase& gui);

    void updategui();

private:

    enum class UpgradeType
    {
        Cursor, // CPC Upgrade
        Grandma, // CPS Upgrade
        Farm, // CPS Upgrade
        Mine, // CPS Upgrade
        Factory, // CPS Upgrade
        Bank, // CPS Upgrade
        Temple, // CPS Upgrade
        WizardTower, // CPS Upgrade
        Shipment,// CPS Upgrade
        AlchemyLab, // CPS Upgrade
        Portal, // CPS Upgrade
        TimeMachine, // CPS Upgrade
        AntimatterCondenser, // CPS Upgrade
        Prism, // CPS Upgrade
        Chancemaker, // CPS Upgrade
        FractalEngine, // CPS Upgrade
        Idleverse, // CPS Upgrade
    };

    void clicker(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth = "50%", tgui::Layout sizeHeight = "16.67%", tgui::Layout posX = "25%", tgui::Layout posY = "70%");

    void upgradeclicker(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, UpgradeType upgradetext);

    void staticguicreator(tgui::GuiBase& gui, const std::string ButtonText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY);

    void print_someting(const std::string& text);

    void cps_label(tgui::GuiBase& gui, std::string displaytext, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY);

    int baseCost = 1;  // Example base cost (you can change this for each building upgrade =) )

    double upgradePrice = 0;

    double calculateUpgradePrice(long long baseCost, int currentCount);

    // Upgrade counts

    int cursor = 0; // CPC Upgrade
    int grandma_count = 0; // CPS Upgrade
    int farm = 0; // CPS Upgrade
    int mine = 0; // CPS Upgrade
    int factory = 0; // CPS Upgrade
    int bank = 0; // CPS Upgrade
    int temple = 0; // CPS Upgrade
    int wizard_tower = 0; // CPS Upgrade
    int shipment = 0; // CPS Upgrade
    int alchemy_lab = 0; // CPS Upgrade
    int portal = 0; // CPS Upgrade
    int time_machine = 0; // CPS Upgrade
    int antimatter_condenser = 0; // CPS Upgrade
    int prism = 0; // CPS Upgrade
    int chancemaker = 0; // CPS Upgrade
    int fractal_engine = 0; // CPS Upgrade
    int idleverse = 0; // CPS Upgrade
    
    sf::Clock cpstimer;

    // Main Components

    // Wanted this int to be able to store a larger number than 2.1 billion so i used LONG LONG cause apparently thats a thing that stores larger numbers cool wallah
    double cookies = 0;

    double cpc = 1;

    double cps = 0;

};

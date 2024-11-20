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

    enum class ClickerupgradeType
    {
        Clicker2, // CPC Upgrade had to name it clicker2 due to clicker being another function with the type void
        GoldenClicker, // CPC Upgrade
        PlatinunClicker, // CPC Upgrade
        EmeraldClicker, // CPC Upgrade
        DiamondClicker, // CPC Upgrade
        MasterClicker, // CPC Upgrade
        ChallengerClicker, // CPC Upgrade
    };

    void clicker_button(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth = "", tgui::Layout sizeHeight = "", tgui::Layout posX = "35%", tgui::Layout posY = "35%");
        
    tgui::Label::Ptr cookieLabel;

    tgui::Label::Ptr cpslabel;

    tgui::Label::Ptr upgradeslabel;


        void upgradeclicker(tgui::GuiBase & gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, UpgradeType upgradetext);

        void clickerupgrades(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, ClickerupgradeType upgradetext);

        void cookie_label(tgui::GuiBase & gui, const std::string ButtonText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY);

        void print_someting(const std::string & text);

        void cps_label(tgui::GuiBase & gui, std::string displaytext, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY);

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

        // Clicker Upgrade Counts
        int clicker2 = 0;
        int goldenclicker = 0;
        int platinumclicker = 0;
        int emeraldclicker = 0;
        int diamondclicker = 0;
        int masterclicker = 0;
        int challengerclicker = 0;

        sf::Clock cpstimer;

        // Main Components

        // Wanted this int to be able to store a larger number than 2.1 billion so i used LONG LONG cause apparently thats a thing that stores larger numbers cool wallah
        float cookies = 0;

        int cpc = 1;

        float cps = 0;

    };

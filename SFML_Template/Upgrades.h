#pragma once
#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "GUI.h"
#include <vector>
#include <string>

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

class Upgrades
{
public:

    // Constructor
    Upgrades();

    // Deconstructor
    ~Upgrades();

    double getCPS() const;

    double getCookies() const;

    long getCPC() const;

    double getUpgradePrice(UpgradeType type) const;

    double getClickerUpgradePrice(ClickerupgradeType type) const;

    void upgradeclicker(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, UpgradeType upgradetext);

    void clickerupgrades(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, ClickerupgradeType upgradetext);

    void clicker_button(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth = "", tgui::Layout sizeHeight = "", tgui::Layout posX = "30%", tgui::Layout posY = "35%");

    tgui::Label::Ptr cookieLabel;

private:

    // Important Counters that are going to corerespond with gui class =)
    double cookies = 0;
    double cps = 0;
    long cpc = 0;
    double upgradePrice = 0;
    double clickerupgradePrice = 0;

    // Important but not used in any other class =)
    long baseCost = 0;  // Example base cost you can change this for each building upgrade =)

    void print_someting(const std::string& text);

    double calculateUpgradePrice(long long baseCost, int currentCount);

    double calculateclickerUpgradePrice(long long baseCost, int currentCount);

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

};

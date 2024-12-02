#include <iostream>
#include "GUI.h"
#include "cmath" // included because the use of the pow function
#include "Upgrades.h"

GUI::GUI()
{
}

GUI::~GUI()
{
}

//Function to handle printing to console, used for all debugging
void GUI::print_someting(const std::string& text)
{
    std::cout << text << std::endl;
}

// Function to handle the "Cookies Per Second" label
void GUI::cps_label(tgui::GuiBase& gui, std::string displaytext, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY)
{
    cpslabel = tgui::Label::create(displaytext);
    cpslabel->setSize({ sizeWidth, sizeHeight });
    cpslabel->setPosition({ posX, posY });
    cpslabel->getRenderer()->setTextColor(tgui::Color(255, 255, 255));
    cpslabel->setTextSize(20);

    gui.add(cpslabel);
}

// Function to handle the "Cookies Per Cookies" label
void GUI::cpc_label(tgui::GuiBase& gui, std::string displaytext, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY)
{
    cpclabel = tgui::Label::create(displaytext);
    cpclabel->setSize({ sizeWidth, sizeHeight });
    cpclabel->setPosition({ posX, posY });
    cpclabel->getRenderer()->setTextColor(tgui::Color(255, 255, 255));
    cpclabel->setTextSize(20);

    gui.add(cpclabel);
}

//Function to handle the "Cookies" label
void GUI::cookie_label(tgui::GuiBase& gui, const std::string ButtonText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY)
{
    cookieLabel = tgui::Label::create(ButtonText);

    cookieLabel->setSize({ sizeWidth, sizeHeight });
    cookieLabel->setPosition({ posX, posY });
    cookieLabel->getRenderer()->setTextColor(tgui::Color(255, 255, 255));
    cookieLabel->setTextSize(25);

    gui.add(cookieLabel);
}

// Public function to initialize the GUI
bool GUI::RunGUI(tgui::GuiBase& gui, Upgrades& upgrades)
{
    try
    {
        upgrades.clicker_button(gui, "", "Button clicked!", "", "25%, 50%");
        cps_label(gui, "Cookies Per Second: 0", "75%", "25%", "40%", "5%");
        cookie_label(gui,"Cookies: 0", "75%", "25%", "40%", "0%");
        cpc_label(gui, "Cookies Per Click: 0", "75%", "25%", "40%", "10%");

        // Upgrade buttons will be placed on the right side, starting from 0% downwards
        float startingPosY = 0.0f;  // Starting position for the first upgrade
        float spacing = 5.0f;  // Space between buttons in percentage

        float startingPosY2 = 0.0f;  // Starting position for the first cps upgrade
        float spacing2 = 5.0f;  // Space between cps upgrade buttons in percentage



        // Calls the clickerupgrades, which are adjusted vertically
        upgrades.clickerupgrades(gui, "Clicker Upgrade", "Upgraded Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::Clicker2);
        startingPosY2 += spacing2;

        upgrades.clickerupgrades(gui, "Golden Clicker Upgrade", "Upgraded Golden Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::GoldenClicker);
        startingPosY2 += spacing2;

        upgrades.clickerupgrades(gui, "Platinum Clicker Upgrade", "Upgraded Platinum Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::PlatinunClicker);
        startingPosY2 += spacing2;

        upgrades.clickerupgrades(gui, "Emerald Clicker Upgrade", "Upgraded Emerald Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::EmeraldClicker);
        startingPosY2 += spacing2;

        upgrades.clickerupgrades(gui, "Diamond Clicker Upgrade", "Upgraded Diamond Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::DiamondClicker);
        startingPosY2 += spacing2;

        upgrades.clickerupgrades(gui, "Master Clicker Upgrade", "Upgraded Master Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::MasterClicker);
        startingPosY2 += spacing2;

        upgrades.clickerupgrades(gui, "Challenger Clicker Upgrade", "Upgraded Challenger Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::ChallengerClicker);
        startingPosY2 += spacing2;


        // Call the upgradeclicker for each upgrade type, adjusted vertically
        upgrades.upgradeclicker(gui, "Cursor Upgrade", "Upgraded Cursor!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Cursor);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Grandma Upgrade", "Upgraded Grandma!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Grandma);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Farm Upgrade", "Upgraded Farm!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Farm);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Mine Upgrade", "Upgraded Mine!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Mine);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Factory Upgrade", "Upgraded Factory!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Factory);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Bank Upgrade", "Upgraded Bank!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Bank);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Temple Upgrade", "Upgraded Temple!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Temple);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Wizard Tower Upgrade", "Upgraded Wizard Tower!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::WizardTower);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Shipment Upgrade", "Upgraded Shipment!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Shipment);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Alchemy Lab Upgrade", "Upgraded Alchemy Lab!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::AlchemyLab);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Portal Upgrade", "Upgraded Portal!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Portal);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Time Machine Upgrade", "Upgraded Time Machine!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::TimeMachine);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Antimatter Condenser Upgrade", "Upgraded Antimatter Condenser!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::AntimatterCondenser);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Prism Upgrade", "Upgraded Prism!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Prism);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Chancemaker Upgrade", "Upgraded Chancemaker!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Chancemaker);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Fractal Engine Upgrade", "Upgraded Fractal Engine!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::FractalEngine);
        startingPosY += spacing;

        upgrades.upgradeclicker(gui, "Idleverse Upgrade", "Upgraded Idleverse!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Idleverse);
        
        return true;
    }
    catch (const tgui::Exception& e)
    {
        std::cerr << "Failed to load TGUI widgets: " << e.what() << std::endl;
        return false;
    }
}

// Updates the UI
void GUI::updategui(Upgrades& upgrades)
{

    sf::Time time = cpstimer.getElapsedTime();
    
    if (time.asSeconds() >= 1)
    { 
        std::cout << cps << std::endl; // Prints the CPS value for debugging
        cookies += cps;



 

        // Update the label text with the current cps count
        if (cps < 1000) {

            // No formatting needed for values below 1000
            this->cpslabel->setText("Cookies Per Second: " + std::to_string(cps));
            this->cpclabel->setText("Cookies Per Click: " + std::to_string(cpc));
        }
        else {
            // For values >= 1000, find the appropriate unit
            std::vector<std::pair<long long, std::string>> units = {
                {1000000000000000000, " QN"},
                {1000000000000000, " QA"},
                {1000000000000, " T"},
                {1000000000, " B"},
                {1000000, " M"},
                {1000, " K"}
            };

            for (const auto& unit : units) {
                if (cps >= unit.first ) {
                    this->cpslabel->setText("Cookies Per Second: " + std::to_string(cps / unit.first) + unit.second);
                    break;
                }
            }
        }

        // Update the label text with the current cookie count
        if (cookies < 1000) {

            // No formatting needed for values below 1000
            this->cookieLabel->setText("Cookies: " + std::to_string(cookies));
        }
        else {
            // For values >= 1000, find the appropriate unit
            std::vector<std::pair<long long, std::string>> units = {
                {1000000000000000000, " QN"},
                {1000000000000000, " QA"},
                {1000000000000, " T"},
                {1000000000, " B"},
                {1000000, " M"},
                {1000, " K"}
            };

            for (const auto& unit : units) {
                if (cookies >= unit.first) {
                    this->cookieLabel->setText("Cookies: " + std::to_string(cookies / unit.first) + unit.second);
                    break;
                }
            }
        }
        cpstimer.restart();
        }
 }
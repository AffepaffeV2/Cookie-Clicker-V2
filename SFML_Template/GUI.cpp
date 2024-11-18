#include <iostream>
#include "GUI.h"
#include "cmath"

GUI::GUI()
{
}

GUI::~GUI()
{
}


void GUI::print_someting(const std::string& text)
{
    std::cout << text << std::endl;
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


    void GUI::upgradeclicker(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, UpgradeType upgradetext)
    {
       
        auto button = tgui::Button::create(ButtonText);

        // Set the size of the label
        button->setSize({ sizeWidth, sizeHeight });

        // Set the position of the label
        button->setPosition({ posX, posY });

        gui.add(button);

        // Button press event: Upgrade an upgrade depending on what case is used
        button->onPress([this, PrintText, upgradetext]()
            {

                switch (upgradetext)
                {
                case UpgradeType::Cursor:
                    upgradePrice = calculateUpgradePrice(1.5, cursor);
                    break;

                case UpgradeType::Grandma:
                    upgradePrice = calculateUpgradePrice(10, grandma_count);
                    break;

                case UpgradeType::Farm:
                    upgradePrice = calculateUpgradePrice(110, farm);
                    break;

                case UpgradeType::Mine:
                    upgradePrice = calculateUpgradePrice(1200, mine);
                    break;

                case UpgradeType::Factory:
                    upgradePrice = calculateUpgradePrice(13000, factory);
                    break;

                case UpgradeType::Bank:
                    upgradePrice = calculateUpgradePrice(140000, bank);
                    break;

                case UpgradeType::Temple:
                    upgradePrice = calculateUpgradePrice(2000000, temple);
                    break;

                case UpgradeType::WizardTower:
                    upgradePrice = calculateUpgradePrice(33000000, wizard_tower);
                    break;

                case UpgradeType::Shipment:
                    upgradePrice = calculateUpgradePrice(510000000, shipment);
                    break;

                case UpgradeType::AlchemyLab:
                    upgradePrice = calculateUpgradePrice(7500000000, alchemy_lab);
                    break;

                case UpgradeType::Portal:
                    upgradePrice = calculateUpgradePrice(100000000000, portal);
                    break;

                case UpgradeType::TimeMachine:
                    upgradePrice = calculateUpgradePrice(1400000000000, time_machine);
                    break;

                case UpgradeType::AntimatterCondenser:
                    upgradePrice = calculateUpgradePrice(17000000000000, antimatter_condenser);
                    break;

                case UpgradeType::Prism:
                    upgradePrice = calculateUpgradePrice(210000000000000, prism);
                    break;

                case UpgradeType::Chancemaker:
                    upgradePrice = calculateUpgradePrice(2600000000000000, chancemaker);
                    break;

                case UpgradeType::FractalEngine:
                    upgradePrice = calculateUpgradePrice(31000000000000000, fractal_engine);
                    break;

                case UpgradeType::Idleverse:
                    upgradePrice = calculateUpgradePrice(7100000000000000000, idleverse);
                    break;
                }


                if (cookies >= upgradePrice) // Check if the player can afford the upgrade
                {
                    std::cout << upgradePrice << std::endl;
                    cookies -= upgradePrice;  // Deduct the cost from the cookie count wallah =)

                    // Increment the corresponding upgrade counter based on upgrade type
                    switch (upgradetext)
                    {
                    case UpgradeType::Cursor:
                        cursor++;
                        cps += cursor*0.01;
                       
                        break;
                    case UpgradeType::Grandma:
                        grandma_count++;
                        cps += grandma_count * 0.1;
                     
                        break;
                    case UpgradeType::Farm:
                        farm++;
                        cps += farm * 0.8;
                        
                        break;
                    case UpgradeType::Mine:
                        mine++;
                        cps += mine * 4.7;
                        
                        break;
                    case UpgradeType::Factory:
                        factory++;
                        cps += factory * 26;
                        
                        break;
                    case UpgradeType::Bank:
                        bank++;
                        cps += bank * 140;

                        break;
                    case UpgradeType::Temple:
                        temple++;
                        cps += temple * 780;

                        break;
                    case UpgradeType::WizardTower:
                        wizard_tower++;
                        cps += wizard_tower * 4400;

                        break;
                    case UpgradeType::Shipment:
                        shipment++;
                        cps += shipment * 26000;

                        break;
                    case UpgradeType::AlchemyLab:
                        alchemy_lab++;
                        cps += alchemy_lab * 160000;

                        break;
                    case UpgradeType::Portal:
                        portal++;
                        cps += portal * 1000000;

                        break;
                    case UpgradeType::TimeMachine:
                        time_machine++;
                        cps += time_machine * 6500000;

                        break;
                    case UpgradeType::AntimatterCondenser:
                        antimatter_condenser++;
                        cps += antimatter_condenser * 43000000;

                        break;
                    case UpgradeType::Prism:
                        prism++;
                        cps += prism * 290000000;

                        break;
                    case UpgradeType::Chancemaker:
                        chancemaker++;
                        cps += chancemaker * 2100000000;

                        break;
                    case UpgradeType::FractalEngine:
                        fractal_engine++;
                        cps += fractal_engine * 15000000000;

                        break;
                    case UpgradeType::Idleverse:
                        idleverse++;
                        cps += idleverse * 100000000000;

                        break;
                    }
                    print_someting(PrintText);  // Optional: Print a message for debugging
                }
                else
                {
                    std::cout << upgradePrice << std::endl;
                    print_someting("Cannot afford upgrade!");  // Optional: Print a message for debugging
                }
            });
}

// Used double instead of float cause double precision is needed for the formula to work better, might cost a bit performance wise but i have big boi computer
double GUI::calculateUpgradePrice(long long baseCost, int currentCount)
{
    // Took the upgrade formula straight from cookie clicker wiki thats why free count is there =)
    std::cout << "Price: " << upgradePrice << std::endl;
    std::cout << "Cookies before: " << cookies << std::endl;
    std::cout << baseCost << std::endl;
    return upgradePrice = baseCost * pow(1.15, currentCount);
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

void GUI::cps_label(tgui::GuiBase& gui, std::string displaytext, tgui::Layout sizeWidth, tgui::Layout sizeHeight,tgui::Layout posX, tgui::Layout posY) 
{
    cpslabel = tgui::Label::create(displaytext);
    cpslabel->setSize({ sizeWidth, sizeHeight });
    cpslabel->setPosition({ posX, posY });
    cpslabel->getRenderer()->setTextColor(tgui::Color(255, 255, 255));
    cpslabel->setTextSize(25);

    gui.add(cpslabel);
}

// Public function to initialize the GUI
bool GUI::RunGUI(tgui::GuiBase& gui)
{
    try
    {
        clicker(gui, "Click Me", "Button clicked!", "50%, 16.67%", "25%, 70%");
        staticguicreator(gui,"Cookies: 0", "75%", "25%", "0%", "0%");
        cps_label(gui, "Cookies Per Second: 0", "75%", "25%", "0%", "5%");


        // Upgrade buttons will be placed on the right side, starting from 10% downwards
        float startingPosY = 0.0f;  // Starting position for the first upgrade
        float spacing = 5.0f;  // Space between buttons in percentage

        // Call the upgradeclicker for each upgrade type, adjusted vertically

        
        upgradeclicker(gui, "Cursor Upgrade", "Upgraded Cursor!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Cursor);
        startingPosY += spacing;

        upgradeclicker(gui, "Grandma Upgrade", "Upgraded Grandma!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Grandma);
        startingPosY += spacing;

        upgradeclicker(gui, "Farm Upgrade", "Upgraded Farm!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Farm);
        startingPosY += spacing;

        upgradeclicker(gui, "Mine Upgrade", "Upgraded Mine!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Mine);
        startingPosY += spacing;

        upgradeclicker(gui, "Factory Upgrade", "Upgraded Factory!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Factory);
        startingPosY += spacing;

        upgradeclicker(gui, "Bank Upgrade", "Upgraded Bank!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Bank);
        startingPosY += spacing;

        upgradeclicker(gui, "Temple Upgrade", "Upgraded Temple!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Temple);
        startingPosY += spacing;

        upgradeclicker(gui, "Wizard Tower Upgrade", "Upgraded Wizard Tower!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::WizardTower);
        startingPosY += spacing;

        upgradeclicker(gui, "Shipment Upgrade", "Upgraded Shipment!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Shipment);
        startingPosY += spacing;

        upgradeclicker(gui, "Alchemy Lab Upgrade", "Upgraded Alchemy Lab!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::AlchemyLab);
        startingPosY += spacing;

        upgradeclicker(gui, "Portal Upgrade", "Upgraded Portal!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Portal);
        startingPosY += spacing;

        upgradeclicker(gui, "Time Machine Upgrade", "Upgraded Time Machine!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::TimeMachine);
        startingPosY += spacing;

        upgradeclicker(gui, "Antimatter Condenser Upgrade", "Upgraded Antimatter Condenser!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::AntimatterCondenser);
        startingPosY += spacing;

        upgradeclicker(gui, "Prism Upgrade", "Upgraded Prism!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Prism);
        startingPosY += spacing;

        upgradeclicker(gui, "Chancemaker Upgrade", "Upgraded Chancemaker!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Chancemaker);
        startingPosY += spacing;

        upgradeclicker(gui, "Fractal Engine Upgrade", "Upgraded Fractal Engine!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::FractalEngine);
        startingPosY += spacing;

        upgradeclicker(gui, "Idleverse Upgrade", "Upgraded Idleverse!", "20%", "5%", tgui::Layout{ "80%" }, tgui::Layout{ std::to_string(startingPosY) + "%" }, UpgradeType::Idleverse);
        
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
        std::cout << cps << std::endl; // Prints the CPS value
        cookies += cps;
        this->cookieLabel->setText("Cookies: " + std::to_string(cookies));
        this->cpslabel->setText("Cookies Per Second: " + std::to_string(cps));
        cpstimer.restart();
        }
 }

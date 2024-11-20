#include <iostream>
#include "GUI.h"
#include "cmath" // included because the use of the pow function


GUI::GUI()
{
}

GUI::~GUI()
{
}

// Function to calculate the upgrades prices, used double instead of float cause double precision is needed for the formula to work better, might cost a bit performance wise but i have big boi computer
double GUI::calculateUpgradePrice(long long baseCost, int currentCount)
{
    // Took the upgrade formula straight from cookie clicker wiki thats why free count is there =)
    std::cout << "Price: " << upgradePrice << std::endl; // Prints the upgrade price for debugging
    std::cout << "Cookies before: " << cookies << std::endl; // Prints how many cookies you had before purchase for debugging
    std::cout << baseCost << std::endl;
    return upgradePrice = baseCost * pow(1.15, currentCount);
}

//Function to handle printing to console, used for all debugging
void GUI::print_someting(const std::string& text)
{
    std::cout << text << std::endl;
}

// Function to handle the clicker button
void GUI::clicker_button(tgui::GuiBase& gui,const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY)
{

    auto button = tgui::Button::create(ButtonText);

    sf::Texture clickerbutton;
   

    // Loads the texture from the file background.png and checks it it fails to load
    if (!clickerbutton.loadFromFile("cookie2.png"))
    {
        std::cerr << "ERORR, could not load texture";
    }

    sf::Sprite s(clickerbutton);

    auto buttonRenderer = button->getRenderer(); 
    buttonRenderer->setTexture(clickerbutton);
    buttonRenderer->setBorders(0);

    sf::Vector2u textureSize = clickerbutton.getSize(); // Get texture width and height

    // Set the size of the label
    button->setSize({tgui::Layout(textureSize.x), tgui::Layout(textureSize.y)});

    // Set the position of the label
    button->setPosition({tgui::Layout(posX), tgui::Layout(posY)});

    gui.add(button);     

    // Button press event: Update cookie count and refresh label
    button->onPress([this, PrintText]() {
        cookies += cpc; // Increment the cookie count

        // Print to console (for debugging)
        print_someting(PrintText);

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
        });
}

//Function to handle all the CPC upgrades
void GUI::clickerupgrades(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, ClickerupgradeType upgradetext)
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
            case ClickerupgradeType::Clicker2:
                upgradePrice = calculateUpgradePrice(10, clicker2);
                break;

            case ClickerupgradeType::GoldenClicker:
                upgradePrice = calculateUpgradePrice(250, goldenclicker);
                break;

            case ClickerupgradeType::PlatinunClicker:
                upgradePrice = calculateUpgradePrice(6250, platinumclicker);
                break;

            case ClickerupgradeType::EmeraldClicker:
                upgradePrice = calculateUpgradePrice(156250, emeraldclicker);
                break;
                
            case ClickerupgradeType::DiamondClicker:
                upgradePrice = calculateUpgradePrice(3906250, diamondclicker);
                break;

            case ClickerupgradeType::MasterClicker:
                upgradePrice = calculateUpgradePrice(97656250, masterclicker);
                break;
            }


            if (cookies >= upgradePrice) // Check if the player can afford the upgrade
            {
                std::cout << upgradePrice << std::endl;
                cookies -= upgradePrice;  // Deduct the cost from the cookie count wallah =)

                // Increment the corresponding upgrade counter based on clicker upgrade type
                switch (upgradetext)
                {
                case ClickerupgradeType::Clicker2:
                    clicker2 ++;
                    cpc += clicker2;
                    break;
                case ClickerupgradeType::GoldenClicker:
                    goldenclicker ++;
                    cpc += goldenclicker + 1;

                case ClickerupgradeType::PlatinunClicker:
                    platinumclicker++;
                    cpc += platinumclicker + 3;

                case ClickerupgradeType::EmeraldClicker:
                    emeraldclicker++;
                    cpc += emeraldclicker + 7;

                case ClickerupgradeType::DiamondClicker:
                    diamondclicker++;
                    cpc += diamondclicker + 15;

                case ClickerupgradeType::MasterClicker:
                    masterclicker++;
                    cpc += masterclicker + 31;

                case ClickerupgradeType::ChallengerClicker:
                    challengerclicker++;
                    cpc += challengerclicker + 63;
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

//Function to handle all the building/CPS upgrades
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

// Function to handle the "Cookies Per Second" label
void GUI::cps_label(tgui::GuiBase& gui, std::string displaytext, tgui::Layout sizeWidth, tgui::Layout sizeHeight,tgui::Layout posX, tgui::Layout posY) 
{
    cpslabel = tgui::Label::create(displaytext);
    cpslabel->setSize({ sizeWidth, sizeHeight });
    cpslabel->setPosition({ posX, posY });
    cpslabel->getRenderer()->setTextColor(tgui::Color(255, 255, 255));
    cpslabel->setTextSize(20);

    gui.add(cpslabel);
}

// Public function to initialize the GUI
bool GUI::RunGUI(tgui::GuiBase& gui)
{
    try
    {
        clicker_button(gui, "", "Button clicked!", "", "25%, 50%");
        cps_label(gui, "Cookies Per Second: 0", "75%", "25%", "40%", "5%");
        cookie_label(gui,"Cookies: 0", "75%", "25%", "40%", "0%");

        // Upgrade buttons will be placed on the right side, starting from 0% downwards
        float startingPosY = 0.0f;  // Starting position for the first upgrade
        float spacing = 5.0f;  // Space between buttons in percentage

        float startingPosY2 = 0.0f;  // Starting position for the first cps upgrade
        float spacing2 = 5.0f;  // Space between cps upgrade buttons in percentage



        // Calls the clickerupgrades, which are adjusted vertically
        clickerupgrades(gui, "Clicker Upgrade", "Upgraded Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::Clicker2);
        startingPosY2 += spacing2;

        clickerupgrades(gui, "Golden Clicker Upgrade", "Upgraded Golden Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::GoldenClicker);
        startingPosY2 += spacing2;

        clickerupgrades(gui, "Platinum Clicker Upgrade", "Upgraded Platinum Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::PlatinunClicker);
        startingPosY2 += spacing2;

        clickerupgrades(gui, "Emerald Clicker Upgrade", "Upgraded Emerald Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::EmeraldClicker);
        startingPosY2 += spacing2;

        clickerupgrades(gui, "Diamond Clicker Upgrade", "Upgraded Diamond Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::DiamondClicker);
        startingPosY2 += spacing2;

        clickerupgrades(gui, "Master Clicker Upgrade", "Upgraded Master Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::MasterClicker);
        startingPosY2 += spacing2;

        clickerupgrades(gui, "Challenger Clicker Upgrade", "Upgraded Challenger Clicker", "20%", "5%", tgui::Layout{ "0%" }, tgui::Layout{ std::to_string(startingPosY2) + "%" }, ClickerupgradeType::ChallengerClicker);
        startingPosY2 += spacing2;


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
        std::cout << cps << std::endl; // Prints the CPS value for debugging
        cookies += cps;

        // Update the label text with the current cps count
        if (cps < 1000) {

            // No formatting needed for values below 1000
            this->cpslabel->setText("Cookies Per Second: " + std::to_string(cps));
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
                if (cps >= unit.first) {
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

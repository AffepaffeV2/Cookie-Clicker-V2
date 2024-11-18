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


    void GUI::upgradeclicker(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, UpgradeType upgradetext)
    {
      
        switch (upgradetext)
        {
        case UpgradeType::Cursor:
            upgradePrice = calculateUpgradePrice(15, cursor);
            break;

        case UpgradeType::Grandma:
            upgradePrice = calculateUpgradePrice(100, grandma_count);
            break;

        case UpgradeType::Farm:
            upgradePrice = calculateUpgradePrice(1100, farm);
            break;

        case UpgradeType::Mine:
            upgradePrice = calculateUpgradePrice(12000, mine);
            break;

        case UpgradeType::Factory:
            upgradePrice = calculateUpgradePrice(13, factory);
            break;

        case UpgradeType::Bank:
            upgradePrice = calculateUpgradePrice(140, bank);
            break;

        case UpgradeType::Temple:
            upgradePrice = calculateUpgradePrice(200, temple);
            break;

        case UpgradeType::WizardTower:
            upgradePrice = calculateUpgradePrice(33, wizard_tower);
            break;

        case UpgradeType::Shipment:
            upgradePrice = calculateUpgradePrice(41, shipment);
            break;

        case UpgradeType::AlchemyLab:
            upgradePrice = calculateUpgradePrice(750, alchemy_lab);
            break;

        case UpgradeType::Portal:
            upgradePrice = calculateUpgradePrice(10, portal);
            break;

        case UpgradeType::TimeMachine:
            upgradePrice = calculateUpgradePrice(140, time_machine);
            break;

        case UpgradeType::AntimatterCondenser:
            upgradePrice = calculateUpgradePrice(170, antimatter_condenser);
            break;

        case UpgradeType::Prism:
            upgradePrice = calculateUpgradePrice(210, prism);
            break;

        case UpgradeType::Chancemaker:
            upgradePrice = calculateUpgradePrice(2600, chancemaker);
            break;

        case UpgradeType::FractalEngine:
            upgradePrice = calculateUpgradePrice(3100, fractal_engine);
            break;

        case UpgradeType::Idleverse:
            upgradePrice = calculateUpgradePrice(710000, idleverse);
            break;
        }
       
        auto button = tgui::Button::create(ButtonText);

        // Set the size of the label
        button->setSize({ sizeWidth, sizeHeight });

        // Set the position of the label
        button->setPosition({ posX, posY });

        gui.add(button);

        // Button press event: Upgrade an upgrade depending on what case is used
        button->onPress([this, PrintText, upgradetext]()
            {

                if (cookies >= 0) // Check if the player can afford the upgrade
                {
                    std::cout << upgradePrice << std::endl;
                    cookies -= upgradePrice;  // Deduct the cost from the cookie count wallah =)

                    // Increment the corresponding upgrade counter based on upgrade type
                    switch (upgradetext)
                    {
                    case UpgradeType::Cursor:
                        cursor++;
                        break;
                    case UpgradeType::Grandma:
                        grandma_count++;
                        break;
                    case UpgradeType::Farm:
                        farm++;
                        break;
                    case UpgradeType::Mine:
                        mine++;
                        break;
                    case UpgradeType::Factory:
                        factory++;
                        break;
                    case UpgradeType::Bank:
                        bank++;
                        break;
                    case UpgradeType::Temple:
                        temple++;
                        break;
                    case UpgradeType::WizardTower:
                        wizard_tower++;
                        break;
                    case UpgradeType::Shipment:
                        shipment++;
                        break;
                    case UpgradeType::AlchemyLab:
                        alchemy_lab++;
                        break;
                    case UpgradeType::Portal:
                        portal++;
                        break;
                    case UpgradeType::TimeMachine:
                        time_machine++;
                        break;
                    case UpgradeType::AntimatterCondenser:
                        antimatter_condenser++;
                        break;
                    case UpgradeType::Prism:
                        prism++;
                        break;
                    case UpgradeType::Chancemaker:
                        chancemaker++;
                        break;
                    case UpgradeType::FractalEngine:
                        fractal_engine++;
                        break;
                    case UpgradeType::Idleverse:
                        idleverse++;
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
double GUI::calculateUpgradePrice(int baseCost, int currentCount)
{
    // Took the upgrade formula straight from cookie clicker wiki thats why free count is there =)
    //std::cout << "Price: " << upgradePrice << std::endl;
    //std::cout << "Cookies before: " << cookies << std::endl;
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
// Public function to initialize the GUI
bool GUI::RunGUI(tgui::GuiBase& gui)
{
    try
    {
        clicker(gui, "Click Me", "Button clicked!", "50%, 16.67%", "25%, 70%");
        staticguicreator(gui,"Cookies: 0", "75%", "25%", "0%", "0%");


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
        std::cout << time.asMilliseconds() << std::endl; // Prints in console everytime it updates used for debugging
        cookies += cps;
        this->cookieLabel->setText("Cookies: " + std::to_string(cookies));
        cpstimer.restart();
        }
 }

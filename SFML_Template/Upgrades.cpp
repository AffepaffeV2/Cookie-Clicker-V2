#include "Upgrades.h"
#include "GUI.h"
#include <iostream>


Upgrades::Upgrades()
{
}



Upgrades::~Upgrades()
{
}


// Function to calculate the upgrades prices, used double instead of float cause double precision is needed for the formula to work better, might cost a bit performance wise but i have big boi computer
double Upgrades::calculateUpgradePrice(long long baseCost, int currentCount)
{
    // Took the upgrade formula straight from cookie clicker wiki thats why free count is there =)
    std::cout << "Price Before: " << upgradePrice << std::endl; // Prints the upgrade price for debugging
    std::cout << "Cookies before: " << cookies << std::endl; // Prints how many cookies you had before purchase for debugging
    return upgradePrice = baseCost * pow(1.15, currentCount);
}

// Same as above but for clicker upgrades =)
double Upgrades::calculateclickerUpgradePrice(long long baseCost, int currentCount)
{
    // Took the upgrade formula straight from cookie clicker wiki thats why free count is there =)
    std::cout << "Price Before: " << clickerupgradePrice << std::endl; // Prints the upgrade price for debugging
    std::cout << "Cookies before: " << cookies << std::endl; // Prints how many cookies you had before purchase for debugging
    return clickerupgradePrice = baseCost * pow(1.15, currentCount);
}

// Function to handle the cookie click button
void Upgrades::clicker_button(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY)
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
    button->setSize({ tgui::Layout(textureSize.x), tgui::Layout(textureSize.y) });

    // Set the position of the label
    button->setPosition({ tgui::Layout(posX), tgui::Layout(posY) });

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

// Function to handle printing to console, used for all debugging
void Upgrades::print_someting(const std::string & text)
{
    std::cout << text << std::endl;
}

// Function to handle all the cpc upgrades
void Upgrades::clickerupgrades(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, ClickerupgradeType upgradetext)
{

    auto button = tgui::Button::create(ButtonText);
    auto pricelabel = tgui::Label::create();
    sf::Texture upgradebutton;

    if (!upgradebutton.loadFromFile("backgroundupgrade.png"))
    {
        std::cerr << "ERORR, could not load texture";
    }

    auto backgroundrenderer = button->getRenderer();
    backgroundrenderer->setTexture(upgradebutton);
    backgroundrenderer->setBorders(0);


    sf::Vector2u textureSize = upgradebutton.getSize(); // Get texture width and height

    // Set the size of the label
    button->setSize({ tgui::Layout(textureSize.x), tgui::Layout(textureSize.y) });

    // Set the position of the label
    button->setPosition({ posX, posY });
    pricelabel->setPosition({ posX + 10, posY + textureSize.y - 30 });

    auto updatePriceDisplay2 = [this, pricelabel, upgradetext]()

        {
            double upgradePrice = 0;
            switch (upgradetext)
            {
            case ClickerupgradeType::Clicker2:
                upgradePrice = calculateclickerUpgradePrice(10, clicker2);
                break;

            case ClickerupgradeType::GoldenClicker:
                upgradePrice = calculateclickerUpgradePrice(250, goldenclicker);
                break;

            case ClickerupgradeType::PlatinunClicker:
                upgradePrice = calculateclickerUpgradePrice(6250, platinumclicker);
                break;

            case ClickerupgradeType::EmeraldClicker:
                upgradePrice = calculateclickerUpgradePrice(156250, emeraldclicker);
                break;

            case ClickerupgradeType::DiamondClicker:
                upgradePrice = calculateclickerUpgradePrice(3906250, diamondclicker);
                break;

            case ClickerupgradeType::MasterClicker:
                upgradePrice = calculateclickerUpgradePrice(97656250, masterclicker);
                break;

            case ClickerupgradeType::ChallengerClicker:
                upgradePrice = calculateclickerUpgradePrice(2441406250, challengerclicker);
                break;
            }

            // Update the label's text with the new price
            pricelabel->setText("Price: " + std::to_string(clickerupgradePrice));
        };

    // Call the update function initially to display the price
    updatePriceDisplay2();

    gui.add(button);
    gui.add(pricelabel);
    // Button press event: Upgrade an upgrade depending on what case is used
    button->onPress([this, PrintText, upgradetext, updatePriceDisplay2, pricelabel]()
        {

            switch (upgradetext)
            {
            case ClickerupgradeType::Clicker2:
                upgradePrice = calculateclickerUpgradePrice(10, clicker2);
                break;

            case ClickerupgradeType::GoldenClicker:
                upgradePrice = calculateclickerUpgradePrice(250, goldenclicker);
                break;

            case ClickerupgradeType::PlatinunClicker:
                upgradePrice = calculateclickerUpgradePrice(6250, platinumclicker);
                break;

            case ClickerupgradeType::EmeraldClicker:
                upgradePrice = calculateclickerUpgradePrice(156250, emeraldclicker);
                break;

            case ClickerupgradeType::DiamondClicker:
                upgradePrice = calculateclickerUpgradePrice(3906250, diamondclicker);
                break;

            case ClickerupgradeType::MasterClicker:
                upgradePrice = calculateclickerUpgradePrice(97656250, masterclicker);
                break;

            case ClickerupgradeType::ChallengerClicker:
                upgradePrice = calculateclickerUpgradePrice(2441406250, challengerclicker);
                break;
            }


            if (cookies >= clickerupgradePrice) // Check if the player can afford the upgrade
            {
                std::cout << clickerupgradePrice << std::endl;
                cookies -= clickerupgradePrice;  // Deduct the cost from the cookie count wallah =)

                // Increment the corresponding upgrade counter based on clicker upgrade type
                switch (upgradetext)
                {
                case ClickerupgradeType::Clicker2:
                    clicker2++;
                    cpc += clicker2;
                    break;
                case ClickerupgradeType::GoldenClicker:
                    goldenclicker++;
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
                std::cout << clickerupgradePrice << std::endl;
                print_someting("Cannot afford upgrade!");  // Optional: Print a message for debugging
            }

            updatePriceDisplay2();

        });
}

// Function to handle all the cps upgrades
void Upgrades::upgradeclicker(tgui::GuiBase& gui, const std::string ButtonText, const std::string PrintText, tgui::Layout sizeWidth, tgui::Layout sizeHeight, tgui::Layout posX, tgui::Layout posY, UpgradeType upgradetext)
{

    auto button = tgui::Button::create(ButtonText);

    auto pricelabel = tgui::Label::create();

    pricelabel->setText("Price");

    sf::Texture upgrade2button;

    if (!upgrade2button.loadFromFile("backgroundupgrade.png"))
    {
        std::cerr << "ERORR, could not load texture";
    }

    auto backgroundrenderer = button->getRenderer();
    backgroundrenderer->setTexture(upgrade2button);
    backgroundrenderer->setBorders(0);



    sf::Vector2u textureSize = upgrade2button.getSize(); // Get texture width and height

    // Set the size of the label
    button->setSize({ tgui::Layout(textureSize.x), tgui::Layout(textureSize.y) });

    // Set the position of the label
    button->setPosition({ posX, posY });

    pricelabel->setPosition({ posX + 10, posY + textureSize.y - 30 });
    auto updatePriceDisplay = [this, pricelabel, upgradetext]() {
        // Calculate the upgrade price based on the type of upgrade
        double upgradePrice = 0;
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
        pricelabel->setText("Price: " + std::to_string(upgradePrice));
        };

    // Call the update function initially to display the price
    updatePriceDisplay();

    // Add the button and the price label to the GUI
    gui.add(button);
    gui.add(pricelabel);

    // Button press event: Upgrade an upgrade depending on what case is used
    button->onPress([this, PrintText, upgradetext, updatePriceDisplay, pricelabel]()
        {
            double upgradePrice = 0;
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
                    cps += cursor * 0.01;

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

            updatePriceDisplay();

        });
}

// Functions to get the coresponding values outside of this class
double Upgrades::getCPS() const {
    return cps;
}

double Upgrades::getCookies() const {
    return cookies;
}

long Upgrades::getCPC() const {
    return cpc;
}

double Upgrades::getUpgradePrice(UpgradeType type) const
{
    return upgradePrice;
}

double Upgrades::getClickerUpgradePrice(ClickerupgradeType type) const
{
    return clickerupgradePrice;
}
#include "Upgrades.h"
#include "GUI.h"
Upgrades::Upgrades()
{
}

Upgrades::~Upgrades()
{
}

void Upgrades::print_someting(const std::string& text)
{
	std::cout << text;
}

void Upgrades::upgradebuttoncreator(tgui::GuiBase& gui, std::string ButtonText, std::string PrintText, std::string upgradetext, tgui::Layout posX, tgui::Layout posY)
{

	auto button = tgui::Button::create(ButtonText);

}


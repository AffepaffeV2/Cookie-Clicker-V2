#pragma once
#include<iostream>
#include<string>
#include <TGUI/TGUI.hpp>
#include "GUI.h"

class Upgrades
{
public:

	//Constructor
	Upgrades();

	//Deconstructor
	~Upgrades();

private:

	//Building List

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

	void upgradebuttoncreator(tgui::GuiBase& gui, std::string ButtonText, std::string PrintText, std::string upgradetext, tgui::Layout posX, tgui::Layout posY);

	void print_someting(const std::string& text);

};

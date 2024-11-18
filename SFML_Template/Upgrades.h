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

	int Cursor = 0; // CPC Upgrade
	int Grandma_count = 0; // CPS Upgrade
	int Farm = 0; // CPS Upgrade
	int Mine = 0; // CPS Upgrade
	int Factory = 0; // CPS Upgrade
	int Bank = 0; // CPS Upgrade
	int Temple = 0; // CPS Upgrade
	int Wizard_tower = 0; // CPS Upgrade
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

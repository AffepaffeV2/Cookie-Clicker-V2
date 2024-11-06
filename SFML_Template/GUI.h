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

	void updategui();

	void rendergui();

private:

	void guicreator(std::string ButtonText, std::string PrintText, tgui::GuiBase& gui, std::string size = "50%, 16.67%", std::string position = "25%, 70%");

	void print_someting(std::string text);
};


#pragma once

#include "BaseMenu.h"
#include "First.h"

class MainMenu : public BaseMenu {

private:

	First* first;

public:

	MainMenu(){}

	~MainMenu() {}

	void load() override {
		int choice{ 0 };
		std::cin >> choice;

		switch (choice) {
		case 1: {
			first = new First(this);
			first->reload();
		}break;
		case 0: {
			exit(1);
		}break;
		}

	}

	void printOptions() override {
		std::cout << "MAIN MENU" << std::endl;
		std::cout << "1. Go to First Sub-Menu" << std::endl;
		std::cout << "0. Exit" << std::endl;
	}
};

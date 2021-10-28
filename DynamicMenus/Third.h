#pragma once
#include "BaseMenu.h"

class Third : public BaseMenu {

private:

public:

	Third(BaseMenu* baseMenu) : BaseMenu(baseMenu) {}

	void load() override {
		int choice{ 0 };
		std::cin >> choice;
		switch (choice) {
		case 1: {
			//Fourth...
		}break;
		case 0: {
			reloadParent();
		}break;
		}

	}

	void printOptions() override {
		std::cout << "THIRD MENU" << std::endl;
		std::cout << "1. Go to x Sub-Menu" << std::endl;
		std::cout << "0. Previous Menu" << std::endl;
	}


};
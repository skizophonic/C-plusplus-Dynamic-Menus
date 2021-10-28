#pragma once

#include "BaseMenu.h"
#include "Second.h"

class First : public BaseMenu{

private:

	Second *second;

public:

	First(BaseMenu *baseMenu) : BaseMenu(baseMenu) {
	
	}

	~First(){}

	void load() override {
		int choice{0};
		std::cin >> choice;
		switch (choice) {
		case 1: {
			second = new Second(this);
			second->reload();
		}break;
		case 0: {
			reloadParent();
		}break;
		}

	}

	void printOptions() override {
		std::cout << "FIRST MENU" << std::endl;
		std::cout << "1. Go to Second Sub-Menu" << std::endl;
		std::cout << "0. Previous Menu" << std::endl;
	}
};
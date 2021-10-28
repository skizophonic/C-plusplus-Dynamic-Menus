#pragma once

#pragma once

#include "BaseMenu.h"
#include "Third.h"


class Second : public BaseMenu {

private:

	Third* third;

public:

	Second(BaseMenu* baseMenu) : BaseMenu(baseMenu) {}

	~Second(){}

	void load() override {
		int choice{ 0 };
		std::cin >> choice;
		switch (choice) {
		case 1: {
			third = new Third(this);
			third->reload();
		}break;
		case 0: {
			reloadParent();
		}break;
		}

	}

	void printOptions() override {
		std::cout << "Entrou no Segundo Menu" << std::endl;
		std::cout << "1. Ir para o Terceiro menu" << std::endl;
		std::cout << "0. Menu Anterior" << std::endl;
	}

	
};
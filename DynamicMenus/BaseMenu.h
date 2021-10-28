#pragma once

// Os Menus são dinâmicos e seguem uma lógica semelhante às listas ligadas (linked Lists)
// O BaseMenu contém os métodos base para os menus, que são depois sobrepostos (Override) pelas sub-classes de menu
// Quando um Sub-menu é criado, este é colocado em memória e é-lhe atribuida uma referência (acontece quando o construor de BaseMenu é acionado). 
// A referencia do menu Pai é passada (this, no sub-menu, atribuido aqui a parent) através do construtor, que será atribuida a this->parent
// Desta forma, é criada a ligação entre as duas estruturas
// Cada menu criado terá um apontador parent, que guarda sempre a posição em memória do objeto anterior. 
// Pode-se utilizar parent para invocar esse objeto, através de reloadParent(). São executadas as funções associadas ao valor de parent desse menu, que irá desencadear o surgimento do menu anterior

//MainMenu this = 0x006ff9dc
//	Cria First através do seu construtor (0x009bf620) e passa o valor 0x006ff9dc para a sua variável apontadora parent, através do construtor de BaseMenu
//First this = 0x009bf620	
//	Cria Second através do seu construtor (0x009bf690) e passa o valor 0x009bf620 para a sua variável apontadora parent, através do construtor de BaseMenu
//Second this = 0x009bf690
//	Cria Third através do seu construtor (0x009bf930) e passa o valor 0x009bf690 para a sua variável apontadora parent, através do construtor de BaseMenu
//Third this = 0x009bf930
// Ao Retroceder no Menu, é executada reloadParent() e, em Third, parent = 0x009bf690 = Second. então, os métodos de Second são executados e o Menu Second surge no ecrã

#include <iostream>

class BaseMenu {

private:

	BaseMenu *parent;

public:

	BaseMenu() = default;						//construtor por defeito de um Menu

	BaseMenu(BaseMenu *parent) {				//construtor para um Sub-Menu. Recebe a referência do menu pai através do apontador parent
		this->parent = parent;					// a referência do menu Pai é atribuida ao menu filho
	}

	virtual void printOptions() {};

	virtual void load() {};

	void clear() {
		std::cout << std::string(50, '\n');
	};

	void reload() {
		this->clear();
		this->printOptions();
		this->load();
	}

	void reloadParent() {
		this->parent->clear();
		this->parent->printOptions();
		this->parent->load();
		this->~BaseMenu();
	}

	void pauseExecution() {
		std::cout << "Press [Enter] to continue . . .";
		std::cin.ignore();
		std::cin.get();
	}
};
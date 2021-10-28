#pragma once

// Os Menus s�o din�micos e seguem uma l�gica semelhante �s listas ligadas (linked Lists)
// O BaseMenu cont�m os m�todos base para os menus, que s�o depois sobrepostos (Override) pelas sub-classes de menu
// Quando um Sub-menu � criado, este � colocado em mem�ria e �-lhe atribuida uma refer�ncia (acontece quando o construor de BaseMenu � acionado). 
// A referencia do menu Pai � passada (this, no sub-menu, atribuido aqui a parent) atrav�s do construtor, que ser� atribuida a this->parent
// Desta forma, � criada a liga��o entre as duas estruturas
// Cada menu criado ter� um apontador parent, que guarda sempre a posi��o em mem�ria do objeto anterior. 
// Pode-se utilizar parent para invocar esse objeto, atrav�s de reloadParent(). S�o executadas as fun��es associadas ao valor de parent desse menu, que ir� desencadear o surgimento do menu anterior

//MainMenu this = 0x006ff9dc
//	Cria First atrav�s do seu construtor (0x009bf620) e passa o valor 0x006ff9dc para a sua vari�vel apontadora parent, atrav�s do construtor de BaseMenu
//First this = 0x009bf620	
//	Cria Second atrav�s do seu construtor (0x009bf690) e passa o valor 0x009bf620 para a sua vari�vel apontadora parent, atrav�s do construtor de BaseMenu
//Second this = 0x009bf690
//	Cria Third atrav�s do seu construtor (0x009bf930) e passa o valor 0x009bf690 para a sua vari�vel apontadora parent, atrav�s do construtor de BaseMenu
//Third this = 0x009bf930
// Ao Retroceder no Menu, � executada reloadParent() e, em Third, parent = 0x009bf690 = Second. ent�o, os m�todos de Second s�o executados e o Menu Second surge no ecr�

#include <iostream>

class BaseMenu {

private:

	BaseMenu *parent;

public:

	BaseMenu() = default;						//construtor por defeito de um Menu

	BaseMenu(BaseMenu *parent) {				//construtor para um Sub-Menu. Recebe a refer�ncia do menu pai atrav�s do apontador parent
		this->parent = parent;					// a refer�ncia do menu Pai � atribuida ao menu filho
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
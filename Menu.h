#pragma once
#include <iostream>
#include <string>
#include "Ferreteria.h"
using namespace std;

class Menu{
private:
	Ferreteria *miFerreteria;
public:
	Menu();
	void MenuPrincipal();
	void opcion1();
	void opcion2();
	void opcion3();
	void opcion4();
	void opcion5();
	void opcion6();
	virtual ~Menu();

};


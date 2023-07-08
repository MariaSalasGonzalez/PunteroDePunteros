#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Herramienta.h"
using namespace std;

class Ferreteria{
private:
	Herramienta **vecHerramienta;
	int cantidad;
	const int tamanno = 100;
public:
	Ferreteria(int cantidad= 0);
	void setCantidad(int cantidad);
	int getCantidad();
	const int getTamanno()const;
	bool buscarHerramienta(int);
	Herramienta *getHerramienta(int);
	string toStringHerramienta();
	string eliminaHerramienta(int);
	void corrimientoVectorHerramienta(int);
	int promedioPrecios();
	bool insertarHerramienta(Herramienta*);
	virtual ~Ferreteria();
};


#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Herramienta{
private:
	int id;
	string nombre;
	float precio;
	int cantidad;
public:
	Herramienta(int id = 0, const string &nombre="", float precio = 0, int cantidad = 0);
	void setId(int id);
	void setNombre(const string &nombre);
	void setPrecio(float precio);
	int getId()const;
	const string &getNombre()const;
	float getPrecio()const;
	int getCantidad()const;
	void setCantidad(int cantidad);
	const string &toString()const;
	virtual ~Herramienta();
};


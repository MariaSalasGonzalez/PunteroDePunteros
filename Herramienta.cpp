#include "Herramienta.h"

Herramienta::Herramienta(int id, const string &nombre, float precio, int cantidad):
                         id(id),nombre(nombre), precio(precio), cantidad(cantidad){}

void Herramienta::setId(int id) {
	Herramienta::id = id;
}

void Herramienta::setNombre(const string &nombre) {
	Herramienta::nombre = nombre;
}

void Herramienta::setCantidad(int cantidad) {
	Herramienta::cantidad = cantidad;
}

void Herramienta::setPrecio(float precio) {
	Herramienta::precio = precio;
}

int Herramienta::getId()const {
	return id;
}

const string &Herramienta::getNombre()const {
	return nombre;
}

float Herramienta::getPrecio() const {
	return precio;
}

int Herramienta::getCantidad() const {
	return cantidad;
}

const string &Herramienta::toString() const {
	stringstream ss;
	ss << "Id: " << getId();
	ss << "Nombre: " << getNombre();
	ss << "Precio: " << getPrecio();
	ss << "Cantidad: " << getCantidad() << endl;
	return ss.str();
}


Herramienta::~Herramienta(){
}

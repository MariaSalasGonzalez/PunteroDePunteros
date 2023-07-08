#include "Ferreteria.h"

Ferreteria::Ferreteria(int cantidad) {
	this->cantidad = cantidad;
	vecHerramienta = new Herramienta *[getTamanno()];
	for (int i = 0; i < getTamanno(); i++) {
		vecHerramienta[i] = nullptr;
	}
}

void Ferreteria::setCantidad(int cantidad) {
	Ferreteria::cantidad = cantidad;
}

int Ferreteria::getCantidad() {
	return cantidad;
}

const int Ferreteria::getTamanno() const{
	return tamanno;
}

bool Ferreteria::buscarHerramienta(int id) {
	for (int i = 0; i < getCantidad(); i++) {
		if (vecHerramienta[i]->getId() == id) {
			return true;
		}
	}
	return false;
}

Herramienta *Ferreteria::getHerramienta(int id) {
	for (int i = 0; i < getCantidad(); i++) {
		if (vecHerramienta[i]->getId() == id) {
			return vecHerramienta[i];
		}
	}
	return nullptr;
}

string Ferreteria::toStringHerramienta() {
	stringstream ss;
	for (int i = 0; i < getCantidad(); i++) {
		ss << "Herramienta: " + to_string(i + 1) + " : ";
		ss << vecHerramienta[i]->toString();
	}
	return ss.str();
}

string Ferreteria::eliminaHerramienta(int id) {
	for (int i = 0; i < getCantidad(); i++) {
		if (vecHerramienta[i]->getId() == id) {
			delete vecHerramienta[i];
			corrimientoVectorHerramienta(i);
			setCantidad(getCantidad() - 1);
			return "Herramienta Eliminada";
		}
	}
	return "Herramienta No Encontrada";
}

void Ferreteria::corrimientoVectorHerramienta(int posicion) {
	for (int i = posicion; i < getCantidad(); i++) {
		vecHerramienta[i] = vecHerramienta[i + 1];
	}
	vecHerramienta[getCantidad() - 1] = nullptr;
}

int Ferreteria::promedioPrecios() {
	float total = 0;
	for (int i = 0; i < getCantidad(); i++) {
		total += vecHerramienta[i]->getPrecio();
	}
	return total / getCantidad();
}

bool Ferreteria::insertarHerramienta(Herramienta* h) {
	if (getCantidad() < getTamanno()) {
		vecHerramienta[getCantidad()] = h;
		setCantidad(getCantidad() + 1);
		return true;
	}
	return false;
}

Ferreteria:: ~Ferreteria(){
	for (int i = 0; i < getCantidad(); i++) {
		delete vecHerramienta[i];
	}
	delete[] vecHerramienta;
	setCantidad(0);
}

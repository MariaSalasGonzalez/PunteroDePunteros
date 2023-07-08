#include "Menu.h"

Menu::Menu() {
	miFerreteria = new Ferreteria;
}
void Menu::MenuPrincipal() {
	int opcion = 0;
	while (opcion != 6) {
		cout << "MENU PRINCIPAL" << endl;
		cout << "OPCION 1: Insertar Herramienta" << endl;
		cout << "OPCION 2: Mostrar Herramienta" << endl;
		cout << "OPCION 3: Mostrar Lista Completa de Herramienta" << endl;
		cout << "OPCION 4: Mostrar Promedio de precios" << endl;
		cout << "OPCION 5: Eliminar una Herramienta" << endl;
		cout << "OPCION 6: Salir" << endl;
		cout << "SELECCIONE UNA OPCION: ";
		cin >> opcion;

		switch (opcion) {
		
		case 1:
			opcion1();
			break;
		case 2:
			opcion2();
			break;
		case 3:
			opcion3();
			break;
		case 4:
			opcion4();
			break;
		case 5:
			opcion5();
			break;
		case 6:
			cout << "Gracias por utilizar nuestros sistemas" << endl;
			break;
		default:
			cout << "LA OPCION SELECCIONADO NO EXISTE";
			break;
		}
	}
	exit(0);
}

void Menu::opcion1() {
	cout << "OPCION 1: INSERTAR HERRAMIENTA" << endl;
	int id;
	string nombre;
	float precio;
	int cantidad;
	cout << "Digite el Id de la herramienta";
	cin >> id;
	cout << "Digite el Nombre de la herramienta";
	cin >> nombre;
	cout << "Digite el Precio de la herramienta";
	cin >> precio;
	cout << "Digite el Cantidad de la herramienta";
	cin >> cantidad;
	if (!miFerreteria->buscarHerramienta(id)) {
		Herramienta *puntTemporal= new Herramienta(id,nombre,precio,cantidad);
		if (miFerreteria->insertarHerramienta(puntTemporal)) {
			cout << "Herramienta insertada!" << endl;
		}
		else {
			cout << "No se pudo insertar la herramienta!" << endl;	
		}
	}else {
		cout << "La Herramienta con ese Id ya existe" << endl;
	}
	cout << "Presione ENTER para continuar" << endl;
	cin.get();
	cin.get();
}

void Menu::opcion2() {
	cout << "OPCION 2: MOSTRAR HERRAMIENTA" << endl;
	int id;
	cout << "Digiite el Id de la herramienta a buscar: ";
	cin >> id;

	Herramienta *temporal = miFerreteria->getHerramienta(id);
	if (temporal != nullptr) {
		cout << temporal->toString();
	}
	else {
		cout << "La herramienta no existe" << endl;
	}
	cout << "Presione ENTER para continuar" << endl;
	cin.get();
	cin.get();
}

void Menu::opcion3() {
	cout << "OPCION 3: MOSTRAR TODAS LAS HERRAMIENTAS" << endl;
	cout << miFerreteria->toStringHerramienta() << endl;
	cout << "Presione ENTER para continuar" << endl;
	cin.get();
	cin.get();
}

void Menu::opcion4() {
	cout << "OPCION 4: MOSTRAR EL PROMEDIO DE PRECIOS" << endl;
	cout << "El promedio de precios es: " << miFerreteria->promedioPrecios() << endl;
	cout << "Presione ENTER para continuar" << endl;
	cin.get();
	cin.get();
}

void Menu::opcion5() {
	cout << "OPCION 5: ELIMINAR UNA HERRAMIENTA" << endl;
	int id;
	cout << "Digite el id de la herramienta a busccar: ";
	cin >> id;

	if (miFerreteria->buscarHerramienta(id)) {
		miFerreteria->eliminaHerramienta(id);
		cout << "Registro Eliminado!";
	}else{
		cout << "Registro No Encontrado";
	}
	cout << "Presione ENTER para continuar" << endl;
	cin.get();
	cin.get();
}

void Menu::opcion6() {
	cout << "Ha salido del menu" << endl;
}

Menu:: ~Menu() {
	delete miFerreteria;
}

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <map>

#include "CLIENTES.h"

class CLIENTES_V {
private:
	Cliente cliente;
	std::vector<Cliente> vector_cliente;

	// Metodos aux
	bool check_chars(char source, char check1, char check2) {
		if (source == check1 || source == check2) {
			return true;
		}
		return false;
	}

	bool check_strings(std::string source) {
		char especiales[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`', ' ', '°' };
		for (char c : source) {
			if (std::isdigit(c)) {
				return true;
			}
			for (char e : especiales) {
				if (c == e) {
					return true;
				}
			}
		}
		return false;
	}

	bool contains_stringTochar(std::string str, char* arr) {
		for (int i = 0; i < strlen(arr); i++) {
			if (strchr(str.c_str(), arr[i]) != NULL) {	//c_str convierte una string en un char*
				return true;
			}
		}
		return false;
	}

	Cliente get(int pos) {
		return vector_cliente[pos];
	}

	void quick_sort(std::vector<Cliente>& vect) {
		if (vect.size() <= 1) {
			return;
		}
		int pivot = vect.size() / 2;
		std::vector<Cliente> left;
		std::vector<Cliente> right;
		for (int i = 0; i < vect.size(); i++) {
			if (i != pivot) {
				if (vect[i].get_codigo() < vect[pivot].get_codigo()) {
					left.push_back(vect[i]);
				}
				else {
					right.push_back(vect[i]);
				}
			}
		}
		quick_sort(left);
		quick_sort(right);
		left.push_back(vect[pivot]);
		for (int i = 0; i < right.size(); i++) {
			left.push_back(right[i]);
		}
		vect = left;
	}

	// Metodos main
	Cliente busqueda_nombre(std::string b_nomb, std::vector<Cliente> vect) {
		int inicio = 0;
		int fin = vect.size() - 1;
		int medio;
		while (inicio <= fin) {
			medio = (inicio + fin) / 2;
			if (vect[medio].get_nombre() == b_nomb) {
				return vect[medio];
			}
			else if (vect[medio].get_nombre() < b_nomb) {
				inicio = medio + 1;
			}
			else {
				fin = medio - 1;
			}
		}
		return Cliente();
	}

	Cliente busqueda_apellido(std::string b_ape, std::vector<Cliente> vect) {
		int inicio = 0;
		int fin = vect.size() - 1;
		int medio;
		while (inicio <= fin) {
			medio = (inicio + fin) / 2;
			if (vect[medio].get_apellido() == b_ape) {
				return vect[medio];
			}
			else if (vect[medio].get_apellido() < b_ape) {
				inicio = medio + 1;
			}
			else {
				fin = medio - 1;
			}
		}
		return Cliente();
	}

	Cliente busqueda_tarjeta(char b_trj, std::vector<Cliente> vect) {
		int inicio = 0;
		int fin = vect.size() - 1;
		int medio;
		while (inicio <= fin) {
			medio = (inicio + fin) / 2;
			if (vect[medio].get_tarjeta() == b_trj) {
				return vect[medio];
			}
			else if (vect[medio].get_tarjeta() < b_trj) {
				inicio = medio + 1;
			}
			else {
				fin = medio - 1;
			}
		}
		return Cliente();
	}

	Cliente busqueda_registro(char b_reg, std::vector<Cliente> vect) {
		int inicio = 0;
		int fin = vect.size() - 1;
		int medio;
		while (inicio <= fin) {
			medio = (inicio + fin) / 2;
			if (vect[medio].get_registrado_web() == b_reg) {
				return vect[medio];
			}
			else if (vect[medio].get_registrado_web() < b_reg) {
				inicio = medio + 1;
			}
			else {
				fin = medio - 1;
			}
		}
		return Cliente();
	}

	int getPostArray(Cliente obj)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (obj.get_codigo() == get(i).get_codigo())
			{
				return i;
			}
		}
		return -1;
	}

public:
	// Metodos auxiliares
	void vector_add(Cliente obj) {
		vector_cliente.push_back(obj);
	}

	int rows() {
		return vector_cliente.size();
	}

	void remove(Cliente obj)
	{
		vector_cliente.erase(vector_cliente.begin() + getPostArray(obj));
	}

	//Metodos main
	void cliente_modificar() {
		int rpta_mod;
		std::string dato_new; std::string opc_mod;
		char opciones[5] = { '0', '1', '2', '3', '4' };

		std::cout << "¿Cual es el tipo de dato que desea modificar?\n";
		std::cout << "1. Nombre\n";
		std::cout << "2. Apellido\n";
		std::cout << "3. Posesion de tarjeta VENTA+\n";
		std::cout << "4. Registrado en la web\n";
		std::cout << "0. Volver";
		do {
			std::cout << ":: ";
			std::cin >> opc_mod;
			if (!contains_stringTochar(opc_mod, opciones)) {
				Beep(200, 200);
			}
		} while (!contains_stringTochar(opc_mod, opciones));
		Beep(480, 200);

		if (vector_cliente.size() < 1) {
			Beep(200, 200);
			std::cout << "No hay clientes registrados";
			for (int i = 0; i < 3; i++) {
				std::cout << ".";
				Sleep(100);
			}
			return;
		}

		std::cout << "De que cliente quisiera modificarlo:\n";
		for (int i = 0; i < vector_cliente.size(); i++) {
			std::cout << i + 1 << ". " << vector_cliente[i].get_nombre() << "\n";
		}

		do {
			std::cout << ":: ";
			std::cin >> rpta_mod;
			if (rpta_mod < 1 || rpta_mod > vector_cliente.size() || std::cin.fail()) {
				Beep(200, 200);
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
		} while (rpta_mod < 1 || rpta_mod > vector_cliente.size() || rpta_mod == '\0');
		Beep(480, 200);

		std::cout << "Ingrese el nuevo dato: ";
		std::cin >> dato_new;
		switch (opc_mod[0]) {
		case '1':
			while (dato_new.length() > 50 || dato_new.length() == 0 || check_strings(dato_new)) {
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_nombre(dato_new);
			break;
		case '2':
			while (dato_new.length() > 50 || dato_new.length() == 0 || check_strings(dato_new)) {
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_apellido(dato_new);
			break;
		case '3':
			dato_new[0] = std::toupper(dato_new[0]);
			while (!check_chars(dato_new[0], 'S', 'N') || std::isblank(dato_new[0]) || std::isdigit(dato_new[0])) {
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
				dato_new[0] = std::toupper(dato_new[0]);
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_tarjeta(dato_new[0]);
			break;
		case '4':
			dato_new[0] = std::toupper(dato_new[0]);
			while (!check_chars(dato_new[0], 'S', 'N') || std::isblank(dato_new[0]) || std::isdigit(dato_new[0])) {
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
				dato_new[0] = std::toupper(dato_new[0]);
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_registrado(dato_new[0]);
			break;
		case '0':
			Beep(480, 200);
			std::cout << "Volviendo a la ventana anterior";
			for (int i = 0; i < 3; i++) {
				std::cout << ".";
				Sleep(100);
			}
			cliente.pantalla_cliente();
			break;

		default:
			Beep(200, 200);
			std::cout << "Opcion no valida. Volviendo al inicio\n";
			for (int i = 0; i < 3; i++) {
				std::cout << ".";
				Sleep(100);
			}
			Sleep(1000);
			system("cls");
			cliente_modificar();
			break;
		}
	}

	void cliente_consultar() {
		std::string rpta_cons;
		std::vector<Cliente> vector_cliente_aux;

		char opciones[5] = { '0', '1', '2', '3', '4' };
		/*Cda opcion tendra su propia funcion en donde se retorne objetos de clase Cliente para luego compararlos una vez que se llamen
		Logrando que cda combinación sea compatible*/

		std::cout << "A partir de que dato(s) desea consultar:\nEn caso de eleccion doble, escribir ambas opciones juntas\n";
		std::cout << "1. Nombre\n";
		std::cout << "2. Apellido\n";
		std::cout << "3. Posesion de tarjeta VENTA+\n";
		std::cout << "4. Registrado en la web\n";
		std::cout << "0. Volver\n";

		std::cout << ":: ";
		std::cin >> rpta_cons;
		while (contains_stringTochar(rpta_cons, opciones) && rpta_cons.length() <= 2 || rpta_cons[1] == '0') {
			Beep(200, 200);
			std::cout << ":: ";
			std::cin >> rpta_cons;
		}
		Beep(480, 200);

		std::string busq;
		std::cout << "Ingrese el dato a buscar: ";
		std::cin >> busq;

		switch (rpta_cons[0]) {
		case '1':
			while (busq.length() > 50 || busq.length() == 0 || check_strings(busq)) {
				Beep(200, 200);
				std::cout << "Ingrese el dato a buscar: ";
				std::cin >> busq;
			}
			Beep(480, 200);
			vector_cliente_aux.push_back(busqueda_nombre(busq, vector_cliente));
			break;

		case '2':
			while (busq.length() > 50 || busq.length() == 0 || check_strings(busq)) {
				Beep(200, 200);
				std::cout << "Ingrese el dato a buscar: ";
				std::cin >> busq;
			}
			Beep(480, 200);
			vector_cliente_aux.push_back(busqueda_apellido(busq, vector_cliente));
			break;

		case '3':
			busq[0] = std::toupper(busq[0]);
			while (!check_chars(busq[0], 'S', 'N') || std::isblank(busq[0]) || std::isdigit(busq[0])) {
				Beep(200, 200);
				std::cout << "Ingrese el dato a buscar: ";
				std::cin >> busq[0];
				busq[0] = std::toupper(busq[0]);
			}
			Beep(480, 200);
			vector_cliente_aux.push_back(busqueda_tarjeta(busq[0], vector_cliente));
			break;

		case '4':
			busq[0] = std::toupper(busq[0]);
			while (!check_chars(busq[0], 'S', 'N') || std::isblank(busq[0]) || std::isdigit(busq[0])) {
				Beep(200, 200);
				std::cout << "Ingrese el dato a buscar: ";
				std::cin >> busq[0];
				busq[0] = std::toupper(busq[0]);
			}
			Beep(480, 200);
			vector_cliente_aux.push_back(busqueda_registro(busq[0], vector_cliente));
			break;

		case '0':
			Beep(480, 200);
			std::cout << "Volviendo a la ventana anterior";
			for (int i = 0; i < 3; i++) {
				std::cout << ".";
				Sleep(100);
			}
			cliente.pantalla_cliente();
			break;

		default:
			Beep(200, 200);
			std::cout << "Opcion no valida. Volviendo al inicio\n";
			for (int i = 0; i < 3; i++) {
				std::cout << ".";
				Sleep(100);
			}
			Sleep(1000);
			system("cls");
			cliente_consultar();
			break;
		}

		if (rpta_cons[0] != rpta_cons[1]) {
			switch (rpta_cons[1]) {
			case '1':
				while (busq.length() > 50 || busq.length() == 0 || check_strings(busq)) {
					Beep(200, 200);
					std::cout << "Ingrese el dato a buscar: ";
					std::cin >> busq;
				}
				Beep(480, 200);
				vector_cliente_aux.push_back(busqueda_nombre(busq, vector_cliente_aux));
				break;

			case '2':
				while (busq.length() > 50 || busq.length() == 0 || check_strings(busq)) {
					Beep(200, 200);
					std::cout << "Ingrese el dato a buscar: ";
					std::cin >> busq;
				}
				Beep(480, 200);
				vector_cliente_aux.push_back(busqueda_apellido(busq, vector_cliente_aux));
				break;

			case '3':
				busq[0] = std::toupper(busq[0]);
				while (!check_chars(busq[0], 'S', 'N') || std::isblank(busq[0]) || std::isdigit(busq[0])) {
					Beep(200, 200);
					std::cout << "Ingrese el dato a buscar: ";
					std::cin >> busq[0];
					busq[0] = std::toupper(busq[0]);
				}
				Beep(480, 200);
				vector_cliente_aux.push_back(busqueda_tarjeta(busq[0], vector_cliente_aux));
				break;

			case '4':
				busq[0] = std::toupper(busq[0]);
				while (!check_chars(busq[0], 'S', 'N') || std::isblank(busq[0]) || std::isdigit(busq[0])) {
					Beep(200, 200);
					std::cout << "Ingrese el dato a buscar: ";
					std::cin >> busq[0];
					busq[0] = std::toupper(busq[0]);
				}
				Beep(480, 200);
				vector_cliente_aux.push_back(busqueda_registro(busq[0], vector_cliente_aux));
				break;
			default:
				break;
			}
		}

		if (vector_cliente_aux.size() == 0) {
			Beep(200, 200);
			std::cout << "No se encontraron coincidencias\n";
			for (int i = 0; i < 3; i++) {
				std::cout << ".";
				Sleep(100);
			}
			Sleep(1000);
			system("cls");
			cliente_consultar();
		}
		else {
			std::cout << "Se encontraron " << vector_cliente_aux.size() << " coincidencias\n";
			for (int i = 0; i < vector_cliente_aux.size(); i++) {
				std::cout << "Cliente " << i + 1 << ":\n";
				vector_cliente_aux[i].imprimir_cliente();
				std::cout << "-----------------------------------\n";
			}
			std::cout << "Presione una tecla para volver al menu anterior\n";
			std::cin.get();
			system("cls");
			cliente.pantalla_cliente();
		}
	}

	void cliente_eliminar() {
		
	}
};
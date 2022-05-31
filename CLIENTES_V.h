#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

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

	bool contains_stringTochar(std::string str, char* arr) {
		for (int i = 0; i < strlen(arr); i++) {
			if (strchr(str.c_str(), arr[i]) != NULL) {	//c_str convierte una string en un char*
				return true;
			}
		}
		return false;
	}

public:
	// Metodos auxiliares
	void vector_add(Cliente obj) {
		vector_cliente.push_back(obj);
	}
	
	Cliente get(int pos) {
		return vector_cliente[pos];
	}

	int rows() {
		return vector_cliente.size();
	}

	//Metodos main
	void cliente_modificar() {
		int rpta_mod;
		std::string dato_new; std::string opc_mod;
		char opciones[6] = { '0', '1', '2', '3', '4', '5'};
		
		std::cout << "¿Cual es el tipo de dato que desea modificar?\n";
		std::cout << "1. Nombre\n";
		std::cout << "2. Apellido\n";
		std::cout << "3. Sexo\n";
		std::cout << "4. Posesion de tarjeta VENTA+\n";
		std::cout << "5. Registrado en la web\n";
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
			std::cout << i+1 << ". " << vector_cliente[i].get_nombre() << "\n";
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
			while (dato_new.length() > 50 || dato_new.length() == 0) {
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_nombre(dato_new);
			break;
		case '2':
			while (dato_new.length() > 50 || dato_new.length() == 0) {
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_apellido(dato_new);
			break;
		case '3':	//TODO: Verificar que el nuevo dato sea un char valido
			
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_sexo(dato_new[0]);
			break;
		case '4':
			
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_tarjeta(dato_new[0]);
			break;
		case '5':
			
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_tarjeta(dato_new[0]);
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

	Cliente* cliente_consultar() {
		std::string rpta_cons;
		char opciones[6] = { '0', '1', '2', '3', '4', '5' };

		std::cout << "¿A partir de qué dato(s) desea consultar?\nEn caso de eleccion multiple, escribir ambas opciones juntas\n";
		std::cout << "1. Nombre\n";
		std::cout << "2. Apellido\n";
		std::cout << "3. Sexo\n";
		std::cout << "4. Posesion de tarjeta VENTA+\n";
		std::cout << "5. Registrado en la web\n";
		std::cout << "0. Volver\n";

		std::cout << ":: ";
		std::cin >> rpta_cons;
		while (!contains_stringTochar(rpta_cons, opciones) || rpta_cons.length() > 2) {
			Beep(200, 200);
			std::cout << ":: ";
			std::cin >> rpta_cons;
		}
		
	}
	/*Cliente cliente_consultar(char* opc) {
		do {
			std::vector<Cliente> cliente_result;
			
			std::cout << "¿A partir de qué/cuáles dato(s) desea consultar?\nEn caso de elección múltiple, escribir ambas opciones juntas\n";
			std::cout << "1. Nombre\n";
			std::cout << "2. Apellido\n";
			std::cout << "3. Número de celular\n";
			std::cin >> opc;
			
			if (opc[0] == '1') {
				char nombre_consulta[51];
				std::cout << "Ingrese el nombre del cliente a consultar: ";
				std::cin >> nombre_consulta;
				for (Cliente obj : vector_cliente) {
					if (obj.get_nombre() == nombre_consulta) {
						cliente_result.push_back(obj);
					}
				}
			} else if (opc[0] == '2') {
				char apellido_consulta[51];
				std::cout << "Ingrese el apellido del cliente a consultar: ";
				std::cin >> apellido_consulta;
				for (Cliente obj : vector_cliente) {
					if (obj.get_apellido() == apellido_consulta) {
						cliente_result.push_back(obj);
					}
				}
			} else if (opc[0] == '3') {
				char celular_consulta[10];
				std::cout << "Ingrese el número de celular del cliente: ";
				std::cin >> celular_consulta;
				for (Cliente obj : vector_cliente) {
					if (obj.get_celular() == celular_consulta) {
						cliente_result.push_back(obj);
					}
				}
			} else {
				std::cout << "Opción inválida\n";
				Sleep(1000);
				system("cls");
			}

		} while (opc[0] != '1' && opc[0] != '2' && opc[0] != '3');
	}*/
};
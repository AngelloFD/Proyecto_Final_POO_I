#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

#include "CLIENTES.h"

class CLIENTES_V {
private:
	std::vector<Cliente> vector_cliente;

	bool char_contains(char search, char* source) {
		for (int i = 0; i < strlen(source); i++) {
			if (source[i] == search) {
				return true;
			}
		}
		return false;
	}
	
public:
	CLIENTES_V() { std::vector<Cliente> vector_cliente; }
	
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
	Cliente cliente_consultar(char* opc) {
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
					if (strcmp(obj.get_nombre(), nombre_consulta) == 0) {	// strcmp() devuelve 0 si son iguales
						cliente_result.push_back(obj);
					}
				}
			} else if (opc[0] == '2') {
				char apellido_consulta[51];
				std::cout << "Ingrese el apellido del cliente a consultar: ";
				std::cin >> apellido_consulta;
				for (Cliente obj : vector_cliente) {
					if (strcmp(obj.get_apellido(), apellido_consulta) == 0) {
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
	}
};
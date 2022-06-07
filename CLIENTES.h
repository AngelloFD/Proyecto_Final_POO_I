#pragma once

#include <random>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

class Cliente {
private:
	char* generar_codigo() {
		srand(time(0));
		Sleep(1000);
		char letras_numeros[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		char* codigo = new char[10];
		for (int i = 0; i < 9; i++) {
			codigo[i] = letras_numeros[rand() % (sizeof(letras_numeros) - 1)];
		}
		codigo[9] = '\0';
		return codigo;
	}
	char* codigo = generar_codigo();

	std::string nombre = "NULL";
	std::string apellido = "NULL";
	char tarjeta_ventaPlus = '0';
	char registrado_web = '0';

	char correo[101] = "";	/*TODO: CIFRAR*/
	char* generar_correo() {
		srand(time(0));
		if (registrado_web == 'S') {
			strcpy_s(correo, apellido.c_str());
			strcat_s(correo, ".");
			strcat_s(correo, nombre.c_str());
			strcat_s(correo, "@hotmail.com");
			return correo;
		}
		char* err = new char[2];
		err[0] = '0';
		err[1] = '\0';
		return err;
	}

	char* generar_contrasena() {
		if (registrado_web == 'S') {
			char letras_numeros[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			char* contrasena = new char[10];
			for (int i = 0; i < 3; i++) {
				contrasena[i] = apellido[i];
			}
			for (int i = 3; i < 6; i++) {
				contrasena[i] = nombre[i - 3];
			}
			for (int i = 6; i < 9; i++) {
				contrasena[i] = letras_numeros[rand() % (sizeof(letras_numeros) - 1)];
			}
			contrasena[9] = '\0';
			return contrasena;
		}
		char* err = new char[2];
		err[0] = '0';
		err[1] = '\0';
		return err;
	}
	char* contrasena = generar_contrasena(); /*TODO: CIFRAR, GUARDAR EN ARCHIVO BINARIO*/

	char* generar_celular() {
		if (registrado_web == 'S') {
			char numeros[] = "0123456789";
			char* celular = new char[10];
			for (int i = 0; i < 10; i++) {
				if (i == 0) {
					celular[i] = '9';
				}
				else {
					celular[i] = numeros[rand() % (sizeof(numeros) - 1)];
				}
			}
			celular[9] = '\0';
			return celular;
		}
		char* err = new char[2];
		err[0] = '0';
		err[1] = '\0';
		return err;
	}
	char* celular = generar_celular(); /*TODO: CIFRAR, GUARDAR EN ARCHIVO BINARIO*/

	int DNI = 0; /*TODO: CIFRAR, GUARDAR EN ARCHIVO BINARIO*/
	int generar_DNI() {
		DNI = rand() % (99999999 - 10000000) + 10000000;
		return DNI;

	}

	int monto_consumido_semanal = 0; //Se interlazará con venta

	// Auxiliares
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

public:

	Cliente() {};

	//Setters
	void set_nombre(std::string nombre) {
		this->nombre = nombre;
	}

	void set_apellido(std::string apellido) {
		this->apellido = apellido;
	}

	void set_tarjeta(char tj_vp) {
		tarjeta_ventaPlus = tj_vp;
	}

	void set_registrado(char registrado_web) {
		this->registrado_web = registrado_web;
	}

	void set_monto_semanal(int monto_s) {
		monto_consumido_semanal = monto_s;
	}

	//Getters
	char* get_codigo() { return codigo; }

	std::string get_nombre() { return nombre; }

	std::string get_apellido() { return apellido; }

	char get_tarjeta() { return tarjeta_ventaPlus; }

	char get_registrado_web() { return registrado_web; }

	char* get_correo() { return correo; }

	char* get_contrasena() { return contrasena; }

	char* get_celular() { return celular; }

	int get_DNI() { return generar_DNI(); }

	int get_monto_semanal() { return monto_consumido_semanal; }

	//Metodos aux
	void imprimir_cliente() {
		std::cout << "Nombre: " << get_nombre() << '\n';
		std::cout << "Apellido: " << get_apellido() << '\n';
		std::cout << "Tarjeta: " << get_tarjeta() << '\n';
		std::cout << "Registrado: " << get_registrado_web() << '\n';
		std::cout << "Correo: " << get_correo() << '\n';
		std::cout << "Contrasena: " << get_contrasena() << '\n';
		std::cout << "Celular: " << get_celular() << '\n';
		std::cout << "DNI: " << get_DNI() << '\n';
		std::cout << "Monto consumido semanal: " << get_monto_semanal() << '\n';
	}

	// Metodos main
	int pantalla_cliente() {
		int rpta;
		system("cls");
		std::cout << "Registro de Clientes:\n";
		std::cout << "1. Ingresar clientes\n";
		std::cout << "2. Modificar clientes\n";
		std::cout << "3. Eliminar clientes\n";
		std::cout << "4. Busqueda de clientes\n";
		std::cout << "5. Volver\n";

		std::cout << ":: ";
		std::cin >> rpta;
		while (std::cin.fail()) {
			Beep(200, 200);
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << ":: ";
			std::cin >> rpta;
		}
		return rpta;
	}

	Cliente* cliente_agregar() {
		Cliente* cliente = new Cliente();
		std::string nombre; std::string apellido; int DNI = 0; char tarjeta_ventaPlus; char registrado_web;


		std::cout << "Ingrese el nombre del cliente: ";
		std::cin >> nombre;
		while (nombre.length() > 50 || nombre.length() == 0 || check_strings(nombre)) {
			Beep(200, 200);
			std::cout << "Ingrese el nombre del cliente: ";
			std::cin >> nombre;
		}
		Beep(480, 200);

		std::cout << "Ingrese el apellido del cliente: ";
		std::cin >> apellido;
		while (apellido.length() > 50 || apellido.length() == 0 || check_strings(apellido)) {
			Beep(200, 200);
			std::cout << "Ingrese el apellido del cliente: ";
			std::cin >> apellido;
		}
		Beep(480, 200);

		std::cout << "El cliente cuenta con la tarjeta VENTA+ (S/N): ";
		std::cin >> tarjeta_ventaPlus;
		tarjeta_ventaPlus = std::toupper(tarjeta_ventaPlus);
		while (!check_chars(tarjeta_ventaPlus, 'S', 'N') || std::isblank(tarjeta_ventaPlus) || std::isdigit(tarjeta_ventaPlus)) {
			Beep(200, 200);
			std::cout << "El cliente cuenta con la tarjeta VENTA+ (S/N): ";
			std::cin >> tarjeta_ventaPlus;
			tarjeta_ventaPlus = std::toupper(tarjeta_ventaPlus);
		}
		Beep(480, 200);
		if (tarjeta_ventaPlus == 'S') {	/*TODO: VERIFICAR DNI CON DNI YA GENERADO*/
			std::cout << "Ingrese el DNI del cliente para confirmar: ";
			std::cin >> DNI;
			while (std::cin.fail()) {
				Beep(200, 200);
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cout << "Ingrese el DNI del cliente para confirmar: ";
				std::cin >> DNI;
			}
			Beep(480, 200);
		}

		std::cout << "El cliente esta registrado en la pagina web (S/N): ";
		std::cin >> registrado_web;
		registrado_web = std::toupper(registrado_web);
		while (!check_chars(registrado_web, 'S', 'N') || std::isblank(registrado_web) || std::isdigit(registrado_web)) {
			Beep(200, 200);
			std::cout << "El cliente esta registrado en la pagina web (S/N): ";
			std::cin >> registrado_web;
		}
		Beep(480, 200);

		cliente->set_nombre(nombre);
		cliente->set_apellido(apellido);
		cliente->set_tarjeta(tarjeta_ventaPlus);
		cliente->set_registrado(registrado_web);

		return cliente;
	}
};
#pragma once

#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
#include <Windows.h>

class Cliente {
private:
	int codigo = 0;
	std::string nombre = "NaN";
	std::string apellido = "NaN";
	char tarjeta_ventaPlus = '0';
	char registrado_web = '0';

	std::string generar_correo() {
		if (registrado_web == 'S') {
			return apellido.substr(0, 3) + "." + nombre.substr(0, 3) + "@outlook.com";
		}
		return "NaN";
	}
	std::string correo = generar_correo();

	std::string generar_contrasena() {
		if (registrado_web = 'S') {
			char letras_numeros[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			std::string contrasena[10];
			for (int i = 0; i < 9; i++) {
				if (i < 3) {
					contrasena[i] = apellido[i];
				}
				else if (i == 3 && i < 6) {
					contrasena[i] = nombre[i];
				}
				else {
					contrasena[i] = letras_numeros[rand() % (sizeof(letras_numeros) - 1)];
				}

			}
			return contrasena[9];
		}
		return "NaN";
	}
	std::string contrasena = generar_contrasena();

	std::string generar_celular() {
		if (registrado_web == 'S') {
			char letras_numeros[] = "0123456789";
			std::string celular[10];
			for (int i = 0; i < 10; i++) {
				if (i == 0) {
					celular[i] = '9';
				}
				celular[i] = letras_numeros[rand() % (sizeof(letras_numeros) - 1)];
			}
			return celular[9];
		}
		return "NaN";
	}
	std::string celular = generar_celular();

	int monto_semanal = 0;

	//Metodos
	//Metodos aux
	bool check_strings(std::string source)
	{
		char especiales[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`', ' ', '�' };
		for (char c : source)
		{
			if (std::isdigit(c))
			{
				return true;
			}
			for (char e : especiales)
			{
				if (c == e)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool check_chars(char source, char check1, char check2)
	{
		if (source == check1 || source == check2)
		{
			return false;
		}
		return true;
	}

public:
	Cliente() {};

	Cliente(std::string nombre, std::string apellido, char tarjeta_ventaPlus, char registrado_web) {
		this->nombre = nombre;
		this->apellido = apellido;
		this->tarjeta_ventaPlus = tarjeta_ventaPlus;
		this->registrado_web = registrado_web;
		this->codigo = codigo += 1;
	}

	//Setters
	void set_nombre(std::string nombre) {
		this->nombre = nombre;
	}
	void set_apellido(std::string apellido) {
		this->apellido = apellido;
	}
	void set_tarjeta_ventaPlus(char tarjeta_ventaPlus) {
		this->tarjeta_ventaPlus = tarjeta_ventaPlus;
	}
	void set_registrado_web(char registrado_web) {
		this->registrado_web = registrado_web;
	}

	//Getters
	int get_codigo() {
		return codigo;
	}
	std::string get_nombre() {
		return nombre;
	}
	std::string get_apellido() {
		return apellido;
	}
	char get_tarjeta_ventaPlus() {
		return tarjeta_ventaPlus;
	}
	char get_registrado_web() {
		return registrado_web;
	}
	std::string get_correo() {
		return correo;
	}
	std::string get_contrasena() {
		return contrasena;
	}
	std::string get_celular() {
		return celular;
	}

	//Metodos
	//Metodos aux
	void imprimir_cliente() {
		std::cout << "Codigo: " << codigo << std::endl;
		std::cout << "Nombre: " << nombre << std::endl;
		std::cout << "Apellido: " << apellido << std::endl;
		std::cout << "Tarjeta de venta Plus: " << tarjeta_ventaPlus << std::endl;
		std::cout << "Registrado en la web: " << registrado_web << std::endl;
		std::cout << "Correo: " << correo << std::endl;
		std::cout << "Contrasena: " << contrasena << std::endl;
		std::cout << "Celular: " << celular << std::endl;
	}

	//Metodos main
	int pantalla_cliente() {
		system("cls");
		int rpta;
		std::cout << "Registro de Clientes:\n";
		std::cout << "1. Ingresar clientes\n";
		std::cout << "2. Modificar clientes\n";
		std::cout << "3. Eliminar clientes\n";
		std::cout << "4. Busqueda de clientes\n";
		std::cout << "5. Volver\n";

		std::cout << ":: ";
		std::cin >> rpta;
		while (std::cin.fail())
		{
			Beep(200, 200);
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << ":: ";
			std::cin >> rpta;
		}
		return rpta;
	}

	Cliente* cliente_agregar()
	{
		std::string nombre;
		std::string apellido;
		char tarjeta_ventaPlus;
		char registrado_web;

		std::cout << "Ingrese el nombre del cliente: ";
		std::cin >> nombre;
		while (nombre.length() > 50 || nombre.length() == 0 || check_strings(nombre))
		{
			Beep(200, 200);
			std::cout << "Ingrese el nombre del cliente: ";
			std::cin >> nombre;
		}
		Beep(480, 200);

		std::cout << "Ingrese el apellido del cliente: ";
		std::cin >> apellido;
		while (apellido.length() > 50 || apellido.length() == 0 || check_strings(apellido))
		{
			Beep(200, 200);
			std::cout << "Ingrese el apellido del cliente: ";
			std::cin >> apellido;
		}
		Beep(480, 200);

		std::cout << "El cliente cuenta con la tarjeta VENTA+ (S/N): ";
		std::cin >> tarjeta_ventaPlus;
		tarjeta_ventaPlus = std::toupper(tarjeta_ventaPlus);
		while (check_chars(tarjeta_ventaPlus, 'S', 'N') || std::isblank(tarjeta_ventaPlus) || std::isdigit(tarjeta_ventaPlus))
		{
			Beep(200, 200);
			std::cout << "El cliente cuenta con la tarjeta VENTA+ (S/N): ";
			std::cin >> tarjeta_ventaPlus;
			tarjeta_ventaPlus = std::toupper(tarjeta_ventaPlus);
		}
		Beep(480, 200);

		std::cout << "El cliente esta registrado en la pagina web (S/N): ";
		std::cin >> registrado_web;
		registrado_web = std::toupper(registrado_web);
		while (check_chars(registrado_web, 'S', 'N') || std::isblank(registrado_web) || std::isdigit(registrado_web))
		{
			Beep(200, 200);
			std::cout << "El cliente esta registrado en la pagina web (S/N): ";
			std::cin >> registrado_web;
		}
		Beep(480, 200);

		Cliente* cliente = new Cliente(nombre, apellido, tarjeta_ventaPlus, registrado_web);

		return cliente;
	}
};
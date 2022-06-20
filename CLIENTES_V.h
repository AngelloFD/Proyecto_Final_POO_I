#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <string>

#include "CLIENTES.h"

class CLIENTES_V
{
private:
	Cliente cliente;
	std::vector<Cliente> vector_cliente;

	// Metodos aux
	bool check_chars(char source, char check1, char check2)
	{
		if (source == check1 || source == check2)
		{
			return false;
		}
		return true;
	}

	bool check_strings(std::string source)
	{
		char especiales[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`', ' ', '�'};
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

	bool contains_stringTochar(std::string str, char *arr)
	{
		for (int i = 0; i < strlen(arr); i++)
		{
			if (strchr(str.c_str(), arr[i]) != NULL)
			{ // c_str convierte una string en un char*
				return false;
			}
		}
		return true;
	}

	Cliente get(int pos)
	{
		return vector_cliente[pos];
	}

	void quick_sort(std::vector<Cliente> &vect)
	{
		if (vect.size() <= 1)
		{
			return;
		}
		size_t pivot = vect.size() / 2;
		std::vector<Cliente> left;
		std::vector<Cliente> right;
		for (int i = 0; i < vect.size(); i++)
		{
			if (i != pivot)
			{
				if (vect[i].get_codigo() < vect[pivot].get_codigo())
				{
					left.push_back(vect[i]);
				}
				else
				{
					right.push_back(vect[i]);
				}
			}
		}
		quick_sort(left);
		quick_sort(right);
		left.push_back(vect[pivot]);
		for (int i = 0; i < right.size(); i++)
		{
			left.push_back(right[i]);
		}
		vect = left;
	}

	// Metodos main
	Cliente busqueda_nombre(std::string b_nomb, std::vector<Cliente> vect)
	{
		int inicio = 0;
		size_t fin = vect.size() - 1;
		int medio;
		while (inicio <= fin)
		{
			medio = (inicio + fin) / 2;
			if (vect[medio].get_nombre() == b_nomb)
			{
				return vect[medio];
			}
			else if (vect[medio].get_nombre() < b_nomb)
			{
				inicio = medio + 1;
			}
			else
			{
				fin = medio - 1;
			}
		}
		return Cliente();
	}

	Cliente busqueda_apellido(std::string b_ape, std::vector<Cliente> vect)
	{
		int inicio = 0;
		size_t fin = vect.size() - 1;
		int medio;
		while (inicio <= fin)
		{
			medio = (inicio + fin) / 2;
			if (vect[medio].get_apellido() == b_ape)
			{
				return vect[medio];
			}
			else if (vect[medio].get_apellido() < b_ape)
			{
				inicio = medio + 1;
			}
			else
			{
				fin = medio - 1;
			}
		}
		return Cliente();
	}

	Cliente busqueda_tarjeta(char b_trj, std::vector<Cliente> vect)
	{
		int inicio = 0;
		size_t fin = vect.size() - 1;
		int medio;
		while (inicio <= fin)
		{
			medio = (inicio + fin) / 2;
			if (vect[medio].get_tarjeta_ventaPlus() == b_trj)
			{
				return vect[medio];
			}
			else if (vect[medio].get_tarjeta_ventaPlus() < b_trj)
			{
				inicio = medio + 1;
			}
			else
			{
				fin = medio - 1;
			}
		}
		return Cliente();
	}

	Cliente busqueda_registro(char b_reg, std::vector<Cliente> vect)
	{
		int inicio = 0;
		size_t fin = vect.size() - 1;
		int medio;
		while (inicio <= fin)
		{
			medio = (inicio + fin) / 2;
			if (vect[medio].get_registrado_web() == b_reg)
			{
				return vect[medio];
			}
			else if (vect[medio].get_registrado_web() < b_reg)
			{
				inicio = medio + 1;
			}
			else
			{
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
	void vector_add(Cliente obj)
	{
		vector_cliente.push_back(obj);
	}

	size_t rows()
	{
		return vector_cliente.size();
	}

	void remove(Cliente obj)
	{
		vector_cliente.erase(vector_cliente.begin() + getPostArray(obj));
	}

	// Metodos main
	void archivo_grabar() {
		try {
			std::fstream archivo_cliente;
			archivo_cliente.open("DATA_CLIENTES.csv", std::ios::app);
			if (archivo_cliente.is_open()) {
				for (int i = 0; i < rows(); i++) {
					archivo_cliente << vector_cliente[i].get_codigo() << "," << vector_cliente[i].get_nombre() << "," << vector_cliente[i].get_apellido() << "," << vector_cliente[i].get_tarjeta_ventaPlus() << "," << vector_cliente[i].get_registrado_web() << '\n';
				}
				archivo_cliente.close();
			}
		}
		catch (std::exception e) {
			throw "Ocurrio un error al grabar en el registro";
		}
	}

	void archivo_modificar() {
		try
		{
			std::cout << "Modificando...";
			std::fstream archivo_cliente;
			archivo_cliente.open("DATA_CLIENTES.csv", std::ios::out);
			if (archivo_cliente.is_open())
			{
				for (Cliente x : vector_cliente)
				{
					archivo_cliente << x.get_codigo() << "," << x.get_nombre() << "," << x.get_apellido() << "," << x.get_tarjeta_ventaPlus() << "," << x.get_registrado_web() << '\n';

				}
				archivo_cliente.close();
			}
		}
		catch (std::exception e)
		{
			throw "Ocurrio un error al grabar en el archivo";
		}
	}

	void archivo_cargar_vector() {
		try
		{
			std::cout << "Cargando...";
			int i;
			size_t posi = 0;
			std::string linea;
			std::string temporal[4];
			std::fstream archivo_cliente;
			archivo_cliente.open("DATA_CLIENTES.csv", std::ios::in);
			if (archivo_cliente.is_open()) {
				while (!archivo_cliente.eof()) {
					while (std::getline(archivo_cliente, linea)) {
						i = 0;
						while ((posi == linea.find(";")) != std::string::npos) {
							temporal[i] = linea.substr(0, posi);
							linea.erase(0, posi + 1);
							i++;
						}
						Cliente cliente;
						cliente.set_nombre(temporal[0]);
						cliente.set_apellido(temporal[1]);
						cliente.set_tarjeta_ventaPlus(std::stoi(temporal[2]));
						cliente.set_registrado_web(std::stoi(temporal[3]));
						vector_cliente.push_back(cliente);
					}
				}
			}
		}
		catch (std::exception e)
		{
			throw "Ocurrio un error al leer el archivo";
		}
	}

	void cliente_modificar()
	{
		if (rows() < 1)
		{
			Beep(200, 200);
			std::cout << "No hay clientes registrados";
			for (int i = 0; i < 3; i++)
			{
				std::cout << ".";
				Sleep(100);
			}
			std::cout << '\n';
			return;
		}

		int rpta_mod;
		std::string dato_new;
		std::string opc_mod;
		char opciones[5] = {'0', '1', '2', '3', '4'};

		std::cout << "Cual es el tipo de dato que desea modificar\n";
		std::cout << "1. Nombre\n";
		std::cout << "2. Apellido\n";
		std::cout << "3. Posesion de tarjeta VENTA+\n";
		std::cout << "4. Registrado en la web\n";
		std::cout << "0. Volver\n";
		do
		{
			std::cout << ":: ";
			std::cin >> opc_mod;
			if (contains_stringTochar(opc_mod, opciones) || opc_mod.size() > 1)
			{
				Beep(200, 200);
			}
		} while (contains_stringTochar(opc_mod, opciones) || opc_mod.size() > 1);
		Beep(480, 200);

		if (opc_mod[0] == '0')
		{
			Beep(480, 200);
			std::cout << "Cancelando";
			for (int i = 0; i < 3; i++)
			{
				std::cout << ".";
				Sleep(100);
			}
			std::cout << '\n';
			return;
		}

		std::cout << "De que cliente quisiera modificarlo:\n";
		for (int i = 0; i < rows(); i++)
		{
			std::cout << i + 1 << ". " << vector_cliente[i].get_nombre() << "\n";
		}

		do
		{
			std::cout << ":: ";
			std::cin >> rpta_mod;
			if (rpta_mod < 1 || rpta_mod > rows() || std::cin.fail())
			{
				Beep(200, 200);
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
		} while (rpta_mod < 1 || rpta_mod > rows() || std::cin.fail());
		Beep(480, 200);

		std::cout << "Ingrese el nuevo dato: ";
		std::cin >> dato_new;
		switch (opc_mod[0])
		{
		case '1':
			while (dato_new.length() > 50 || dato_new.length() == 0 || check_strings(dato_new))
			{
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_nombre(dato_new);
			archivo_modificar();
			break;
		case '2':
			while (dato_new.length() > 50 || dato_new.length() == 0 || check_strings(dato_new))
			{
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_apellido(dato_new);
			archivo_modificar();
			break;
		case '3':
			dato_new[0] = std::toupper(dato_new[0]);
			while (check_chars(dato_new[0], 'S', 'N') || std::isblank(dato_new[0]) || std::isdigit(dato_new[0]))
			{
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
				dato_new[0] = std::toupper(dato_new[0]);
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_tarjeta_ventaPlus(dato_new[0]);
			archivo_modificar();
			break;
		case '4':
			dato_new[0] = std::toupper(dato_new[0]);
			while (check_chars(dato_new[0], 'S', 'N') || std::isblank(dato_new[0]) || std::isdigit(dato_new[0]))
			{
				Beep(200, 200);
				std::cout << "Ingrese el nuevo dato: ";
				std::cin >> dato_new;
				dato_new[0] = std::toupper(dato_new[0]);
			}
			Beep(480, 200);
			vector_cliente[rpta_mod - 1].set_registrado_web(dato_new[0]);
			archivo_modificar();
			break;

		default:
			Beep(200, 200);
			std::cout << "Opcion no valida. Volviendo al inicio\n";
			for (int i = 0; i < 3; i++)
			{
				std::cout << ".";
				Sleep(100);
			}
			Sleep(1000);
			system("cls");
			cliente_modificar();
			break;
		}
	}

	void cliente_consultar()
	{
		std::string rpta_opc;
		std::string dato_buscar;
		std::vector<Cliente> vector_cliente_aux;

		char opciones[5] = {'0', '1', '2', '3', '4'};
		std::cout << "Elija a partir de que dato desea buscar:\n";
		std::cout << "1. Nombre\n";
		std::cout << "2. Apellido\n";
		std::cout << "3. Posesion de Tarjeta Venta+\n";
		std::cout << "4. Registrado en la web\n";
		std::cout << "0. Volver\n";

		do
		{
			std::cout << ":: ";
			std::cin >> rpta_opc;
			if (contains_stringTochar(rpta_opc, opciones) || rpta_opc.size() > 1)
			{
				Beep(200, 200);
			}
		} while (contains_stringTochar(rpta_opc, opciones) || rpta_opc.size() > 1);
		Beep(480, 200);

		if (rpta_opc == "0")
		{
			Beep(480, 200);
			std::cout << "Cancelando";
			for (int i = 0; i < 3; i++)
			{
				std::cout << ".";
				Sleep(100);
			}
			std::cout << '\n';
			return;
		}

		std::cout << "Ingrese el dato a buscar: ";
		std::cin >> dato_buscar;

		switch (rpta_opc[0])
		{
		case '1':
		{
			for (int i = 0; i < rows(); i++)
			{
				vector_cliente_aux.push_back(vector_cliente[i]);
			}
			quick_sort(vector_cliente_aux);
			Cliente result = busqueda_nombre(dato_buscar, vector_cliente_aux);
			result.imprimir_cliente();
			break;
		}
		case '2':
		{
			for (int i = 0; i < rows(); i++)
			{
				vector_cliente_aux.push_back(vector_cliente[i]);
			}
			quick_sort(vector_cliente_aux);
			Cliente result = busqueda_apellido(dato_buscar, vector_cliente_aux);
			result.imprimir_cliente();
			break;
		}
		case '3':
		{
			for (int i = 0; i < rows(); i++)
			{
				vector_cliente_aux.push_back(vector_cliente[i]);
			}
			quick_sort(vector_cliente_aux);
			Cliente result = busqueda_tarjeta(dato_buscar[0], vector_cliente_aux);
			result.imprimir_cliente();
			break;
		}
		case '4':
		{
			for (int i = 0; i < rows(); i++)
			{
				vector_cliente_aux.push_back(vector_cliente[i]);
			}
			quick_sort(vector_cliente_aux);
			Cliente result = busqueda_registro(dato_buscar[0], vector_cliente_aux);
			result.imprimir_cliente();
			break;
		}
		default:
		{
			Beep(200, 200);
			std::cout << "Opcion no valida. Volviendo al inicio\n";
			for (int i = 0; i < 3; i++)
			{
				std::cout << ".";
				Sleep(100);
			}
			Sleep(1000);
			system("cls");
			cliente_consultar();
			break;
		}
		}
	}

	void cliente_eliminar()
	{
		int rpta_eliminar;
		std::cout << "Cual cliente desea eliminar: ";
		for (int i = 0; i < rows(); i++)
		{
			std::cout << "Cliente " << i + 1 << ": " << vector_cliente[i].get_codigo() << " || " << vector_cliente[i].get_nombre() << '\n';
		}

		do
		{
			std::cout << ":: ";
			std::cin >> rpta_eliminar;
			if (rpta_eliminar < 1 || rpta_eliminar > rows() || std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(256, '\n');
				Beep(200, 200);
			}
		} while (rpta_eliminar < 1 || rpta_eliminar > rows() || std::cin.fail());
		Beep(480, 200);

		if (vector_cliente[rpta_eliminar - 1].get_codigo() == 0)
		{
			Beep(200, 200);
			std::cout << "El cliente no existe. Volviendo al inicio\n";
			for (int i = 0; i < 3; i++)
			{
				std::cout << ".";
				Sleep(100);
			}
			Sleep(1000);
			system("cls");
			cliente_eliminar();
			return;
		}
		else
		{
			vector_cliente.erase(vector_cliente.begin() + rpta_eliminar - 1);
			std::cout << "Cliente eliminado\n";
			archivo_modificar();
		}
	}

};
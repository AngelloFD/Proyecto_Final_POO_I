#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "cliente.h"

class Cliente_V
{
private:
	std::vector<Cliente> cliente_vector;

	// Metodos aux
	bool check_chars(char source, char check1, char check2)
	{
		if (source == check1 || source == check2)
		{
			return true;
		}
		return false;
	}

	bool check_strings(std::string source)
	{
		char especiales[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/', '~', '`'};
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

public:
	Cliente_V()
	{
		archivo_vector();
		std::vector<Cliente> cliente_vector;
	}

	Cliente buscar_por_cod(int cod)
	{
		for (Cliente clt : cliente_vector)
		{
			if (cod == clt.get_codigo())
			{
				return clt;
			}
		}
		return Cliente();
	}

	// Metodos aux
	void add(Cliente obj)
	{
		cliente_vector.push_back(obj);
	}

	Cliente get(int pos)
	{
		return cliente_vector[pos];
	}

	int pantalla_cliente()
	{
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
		while (std::cin.fail() || rpta < 1 || rpta > 5)
		{
			Beep(200, 200);
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << ":: ";
			std::cin >> rpta;
		}
		return rpta;
	}

	int rows()
	{
		return cliente_vector.size();
	}

	int getPostArray(Cliente clt)
	{
		for (int i = 0; i < rows(); i++)
		{
			if (cliente_vector[i].get_codigo() == clt.get_codigo())
			{
				return i;
			}
		}
		return -1;
	}

	void remove(Cliente clt)
	{
		cliente_vector.erase(cliente_vector.begin() + getPostArray(clt));
	}

	// Metodos manipulacion de archivo
	void archivo_grabar(Cliente clt) // Grabar al archivo csv
	{
		try
		{
			std::fstream archivo_cliente;
			archivo_cliente.open("DATA_CLIENTES.csv", std::ios::app);
			if (archivo_cliente.fail())
			{
				throw std::exception("Error al abrir el archivo");
			}

			if (archivo_cliente.is_open())
			{
				archivo_cliente << clt.get_codigo() << "," << clt.get_nombre() << "," << clt.get_apellido() << "," << clt.get_tarjeta_ventaPlus() << "," << clt.get_registrado_web() << "," << clt.get_correo() << clt.get_contrasena() << clt.get_celular() << "\n";
				archivo_cliente.close();
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
	}

	void archivo_modificar() // Modificar el archivo csv
	{
		try
		{
			std::fstream archivo_cliente;
			archivo_cliente.open("DATA_CLIENTES.csv", std::ios::out);
			if (archivo_cliente.fail())
			{
				throw std::exception("Error al abrir el archivo");
			}

			if (archivo_cliente.is_open())
			{
				for (Cliente c : cliente_vector)
				{
					archivo_cliente << c.get_codigo() << "," << c.get_nombre() << "," << c.get_apellido() << "," << c.get_tarjeta_ventaPlus() << "," << c.get_registrado_web() << "," << c.get_correo() << "," << c.get_contrasena() << "," << c.get_celular() << "\n";
				}
				archivo_cliente.close();
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
	}

	void archivo_vector() // Mover info del archivo csv al vector
	{
		try
		{
			int i;
			size_t posi;
			std::string linea;
			std::string temporal[7];
			std::fstream archivo_cliente;
			archivo_cliente.open("DATA_CLIENTES.csv", std::ios::in);
			if (archivo_cliente.fail())
			{
				throw std::exception("Error al abrir el archivo");
			}

			if (archivo_cliente.is_open())
			{
				while (!archivo_cliente.eof())
				{
					i = 0;
					while ((posi = linea.find(",")) != std::string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						i++;
					}
					Cliente clt;
					clt.set_codigo(std::stoi(temporal[0]));
					clt.set_nombre(temporal[1]);
					clt.set_apellido(temporal[2]);
					clt.set_tarjeta_ventaPlus(std::stoi(temporal[3]));
					clt.set_registrado_web(std::stoi(temporal[4]));
					clt.set_correo(temporal[5]);
					clt.set_contrasena(temporal[6]);
					clt.set_celular((temporal[7]));
					add(clt);
				}
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
	}

	// Metodos main
	void cliente_agregar() // Agregar cliente
	{
		std::string nombre;
		std::string apellido;
		char trjta_vp;
		char reg_web;
		char rpta;

		do
		{
			std::cout << "Nombre:\n";
			std::cin >> nombre;
			while (nombre.length() > 20 || nombre.length() < 3 || check_strings(nombre))
			{
				Beep(200, 200);
				std::cout << "Nombre:\n";
				std::cin >> nombre;
			}
			Beep(480, 200);

			std::cout << "Apellido:\n";
			std::cin >> apellido;
			while (apellido.length() > 20 || apellido.length() < 3 || check_strings(apellido))
			{
				Beep(200, 200);
				std::cout << "Apellido:\n";
				std::cin >> apellido;
			}
			Beep(480, 200);

			std::cout << "Suscrito a la Tarjeta_Venta+:\n";
			std::cin >> trjta_vp;
			trjta_vp = toupper(trjta_vp);
			while (check_chars(trjta_vp, 'S', 'N') == false)
			{
				Beep(200, 200);
				std::cout << "Suscrito a la Tarjeta_Venta+:\n";
				std::cin >> trjta_vp;
				trjta_vp = toupper(trjta_vp);
			}
			Beep(480, 200);

			std::cout << "Registrado en la web:\n";
			std::cin >> reg_web;
			reg_web = toupper(reg_web);
			while (check_chars(reg_web, 'S', 'N') == false)
			{
				Beep(200, 200);
				std::cout << "Registrado en la web:\n";
				std::cin >> reg_web;
				reg_web = toupper(reg_web);
			}
			Beep(480, 200);

			Cliente clt;
			clt.set_nombre(nombre);
			clt.set_apellido(apellido);
			clt.set_tarjeta_ventaPlus(trjta_vp);
			clt.set_registrado_web(reg_web);
			add(clt);
			std::cout << "Desea agregar otro cliente? (S/N)\n";
			std::cout << ":: ";
			std::cin >> rpta;
			rpta = toupper(rpta);
		} while (rpta == 'S');

		system("cls");
	}

	void cliente_modificar() // Modificar cliente
	{
		if (rows() < 1)
		{
			std::cout << "No hay clientes registrados\n";
			return;
		}

		for (int i = 0; i < rows(); i++)
		{
			std::cout << i << ") " << get(i).get_nombre() << " " << get(i).get_apellido() << "\n";
		}
		int codigo;
		std::string dato_new;

		std::cout << "Ingrese el codigo del cliente a modificar:\n";
		std::cin >> codigo;

		Cliente mod_clt = get(codigo);

		std::cout << "Registro encontrado:\n";
		std::cout << "--------------------------------------\n";
		std::cout << "Codigo: " << mod_clt.get_codigo() << "\n";
		std::cout << "Nombre: " << mod_clt.get_nombre() << "\n";
		std::cout << "Apellido: " << mod_clt.get_apellido() << "\n";
		std::cout << "Tarjeta_Venta+: " << mod_clt.get_tarjeta_ventaPlus() << "\n";
		std::cout << "Registrado en la web: " << mod_clt.get_registrado_web() << "\n";

		std::cout << "Dato a modificar:\n";
		std::cout << "1) Nombre\n";
		std::cout << "2) Apellido\n";
		std::cout << "3) Tarjeta_Venta+\n";
		std::cout << "4) Registrado en la web\n";
		int opcion;
		do
		{
			std::cout << ":: ";
			std::cin >> opcion;
		} while (opcion > 4 || opcion < 1);
		Beep(480, 200);

		std::cout << "Ingrese el nuevo dato:\n";
		std::cin >> dato_new;

		switch (opcion)
		{
		case 1:
			while (dato_new.length() > 20 || dato_new.length() < 3 || check_strings(dato_new))
			{
				Beep(200, 200);
				std::cout << "Nombre:\n";
				std::cin >> dato_new;
			}
			Beep(480, 200);

			mod_clt.set_nombre(dato_new);
			break;
		case 2:
			while (dato_new.length() > 20 || dato_new.length() < 3 || check_strings(dato_new))
			{
				Beep(200, 200);
				std::cout << "Apellido:\n";
				std::cin >> dato_new;
			}
			Beep(480, 200);

			mod_clt.set_apellido(dato_new);
			break;
		case 3:
			dato_new[0] = toupper(dato_new[0]);
			while (check_chars(dato_new[0], 'S', 'N') == false)
			{
				Beep(200, 200);
				std::cout << "Suscrito a la Tarjeta_Venta+:\n";
				std::cin >> dato_new[0];
				dato_new[0] = toupper(dato_new[0]);
			}
			Beep(480, 200);

			mod_clt.set_tarjeta_ventaPlus(dato_new[0]);
			break;
		case 4:
			dato_new[0] = toupper(dato_new[0]);
			while (check_chars(dato_new[0], 'S', 'N') == false)
			{
				Beep(200, 200);
				std::cout << "Registrado en la web:\n";
				std::cin >> dato_new[0];
				dato_new[0] = toupper(dato_new[0]);
			}
			Beep(480, 200);

			mod_clt.set_registrado_web(dato_new[0]);
			break;
		default:
			Beep(200, 200);
			std::cout << "Opcion no valida.Volviendo al inicio\n";
			system("cls");
			cliente_modificar();
			break;
		}
	}

	void cliente_consultar() // Buscar cliente
	{
		if (rows() < 1)
		{
			std::cout << "No hay clientes registrados\n";
			return;
		}
		for (int i = 0; i < rows(); i++)
		{
			std::cout << i << ") " << get(i).get_nombre() << " " << get(i).get_apellido() << "\n";
		}
		int codigo;
		std::cout << "Ingrese el codigo del cliente a consultar:\n";
		std::cin >> codigo;
		Cliente clt = get(codigo);
		std::cout << "Registro encontrado:\n";
		std::cout << "--------------------------------------\n";
		std::cout << "Codigo: " << clt.get_codigo() << "\n";
		std::cout << "Nombre: " << clt.get_nombre() << "\n";
		std::cout << "Apellido: " << clt.get_apellido() << "\n";
		std::cout << "Tarjeta_Venta+: " << clt.get_tarjeta_ventaPlus() << "\n";
		std::cout << "Registrado en la web: " << clt.get_registrado_web() << "\n";
	}

	void remove(Cliente clt)
	{
		cliente_vector.erase(cliente_vector.begin() + getPostArray(clt));
	}

	void cliente_eliminar() // Eliminar cliente
	{
		int codigo;
		for (Cliente c : cliente_vector)
		{
			std::cout << c.get_codigo() << "-" << c.get_nombre() << "\n";
		}
		std::cout << "Ingrese el codigo del cliente que desea eliminar:\n";
		std::cin >> codigo;
		while (codigo < 0 || codigo > rows())
		{
			Beep(200, 200);
			std::cout << "Ingrese el codigo del cliente que desea eliminar:\n";
			std::cin >> codigo;
		}

		Cliente clt_del = buscar_por_cod(codigo);
		if (clt_del.get_nombre() != "NaN")
		{
			remove(clt_del);
			std::cout << "Registro eliminado\n";
			archivo_modificar();
		}
		else
		{
			Beep(200, 200);
			std::cout << "Registro no encontrado\n";
		}
	}
};

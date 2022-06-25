#pragma once
#include <iostream>
#include <random>
#include <time.h>
#include <Windows.h>

class Cliente
{
private:
	int codigo = 0;
	std::string nombre = "NaN";
	std::string apellido = "NaN";
	char tarjeta_ventaPlus = 'N';
	char registrado_web = 'N';

	std::string generar_correo()
	{
		if (registrado_web == 'S')
		{
			return apellido.substr(0, 3) + "." + nombre.substr(0, 3) + "@outlook.com";
		}
		return "NaN";
	}
	std::string correo = generar_correo();

	std::string generar_contrasena()
	{
		if (registrado_web = 'S')
		{
			char letras_numeros[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
			std::string contrasena[10];
			for (int i = 0; i < 9; i++)
			{
				if (i < 3)
				{
					contrasena[i] = apellido[i];
				}
				else if (i == 3 && i < 6)
				{
					contrasena[i] = nombre[i];
				}
				else
				{
					contrasena[i] = letras_numeros[rand() % (sizeof(letras_numeros) - 1)];
				}
			}
			return contrasena[9];
		}
		return "NaN";
	}
	std::string contrasena = generar_contrasena();

	std::string generar_celular()
	{
		if (registrado_web == 'S')
		{
			char letras_numeros[] = "0123456789";
			std::string celular[10];
			for (int i = 0; i < 10; i++)
			{
				if (i == 0)
				{
					celular[i] = '9';
				}
				celular[i] = letras_numeros[rand() % (sizeof(letras_numeros) - 1)];
			}
			return celular[9];
		}
		return "NaN";
	}
	std::string celular = generar_celular();

public:
	Cliente(){};

	Cliente(std::string nombre, std::string apellido, char tarjeta_ventaPlus, char registrado_web)
	{
		this->nombre = nombre;
		this->apellido = apellido;
		this->tarjeta_ventaPlus = tarjeta_ventaPlus;
		this->registrado_web = registrado_web;
		this->codigo = codigo += 1;
	}

	// Setters
	void set_nombre(std::string nombre)
	{
		this->nombre = nombre;
	}
	void set_apellido(std::string apellido)
	{
		this->apellido = apellido;
	}
	void set_tarjeta_ventaPlus(char tarjeta_ventaPlus)
	{
		this->tarjeta_ventaPlus = tarjeta_ventaPlus;
	}
	void set_registrado_web(char registrado_web)
	{
		this->registrado_web = registrado_web;
	}
	void set_codigo(int codigo)
	{
		this->codigo = codigo;
	}
	void set_correo(std::string correo)
	{
		this->correo = correo;
	}
	void set_contrasena(std::string contrasena)
	{
		this->contrasena = contrasena;
	}
	void set_celular(std::string celular)
	{
		this->celular = celular;
	}

	// Getters
	int get_codigo()
	{
		return codigo;
	}
	std::string get_nombre()
	{
		return nombre;
	}
	std::string get_apellido()
	{
		return apellido;
	}
	char get_tarjeta_ventaPlus()
	{
		return tarjeta_ventaPlus;
	}
	char get_registrado_web()
	{
		return registrado_web;
	}
	std::string get_correo()
	{
		return correo;
	}
	std::string get_contrasena()
	{
		return contrasena;
	}
	std::string get_celular()
	{
		return celular;
	}
};